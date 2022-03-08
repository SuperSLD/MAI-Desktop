# MAI-Desktop
## Справка по архитектуре
Тут я собрал информацию, которая поможет вести разработку приложения.

## Создание экрана

### Понимание происходящего

На схеме отображена примерная схема архитектуры Qt приложения. Есть набор экранов и фабрика которая умеет создавать экраны по тэгу. Также есть роутер который прослушивает сигналы текущего отображаемого экрана, и по необходимости с помощью фабрики открывает следующий экран.

![](https://github.com/SuperSLD/MAI-Desktop/blob/main/images/архитектура.png?raw=true)

### Новый экран

Для добавления новго экрана нужно создать его, и потом дописать его к фабрике экранов.
```cpp
class TestFragment: public BaseFragment {
    Q_OBJECT
public:
    TestFragment();
    ~TestFragment();
};
```
Вот так выглядит дефолтный пустой экран. унаследованный от BaseFragment и теперь нам надо добавит его название в *namespace screens*  и прописать создание экземпляра экрана в методе создающем их.
```cpp
namespace screens {
    static const QString SERVER_URL = "https://jutter.online/mai_v2";

    static const QString SPLASH_TAG = "splash";
    static const QString SEARCH_GROUP_TAG = "search_group";
    // сюда дописывать новые названия
    static const QString TEST_TAG = "splash";
};
```
И код из самой фабрики:
```cpp
BaseFragment* ImplFragmentFactory::create(QString tag) {
    qDebug("ScreensFactory create");
    if (tag == SPLASH_TAG) {
        return new SplashFragment;
    } else if (tag == SEARCH_GROUP) {
        return new SearchGroupFragment;
    // добавляем ново усолвие, если тэг тот который
    // мы только что добавили, то создаем новый экран
    } else if (tag == TEST_TAG)
        return new TestFragment;
    } else {
        return nullptr;
    }
}
```

### Гайд по навигации в приложении

Основным элементом приложения является Router который координирует действия между экранами, создает новые и передает между ними данными. Список навигационных сигналов отображен на картинке ниже, каждый сигнал имеет дублирующий, который передает вместе с действием какую-то модель данных (потомка BaseModel, чтоб можео было использовать приведение типов)

![](https://github.com/SuperSLD/MAI-Desktop/blob/main/images/навигация.png?raw=true)

---
## Получение данных с сервера

Для получения данных с сервера в приложении используется класс AppNetRepository, который является прослойкой, реализующий все методы обращения к API, для ApiService. Тоесть этот класс содержит в себе все методы для работы с бэком приложения.

![](https://github.com/SuperSLD/MAI-Desktop/blob/main/images/интернет.png?raw=true)

Для получение данных с сервера есть объект, AppNetRepository. В конструкторе экрана мы его создаем, и делаем глобальной переменной, а в деструкторе обязательно его удаляем.
```cpp
// конструктор
SearchGroupFragment::SearchGroupFragment() {
    netRepository = new AppNetRepository();
    // подключаем слот прослушивающий группы к фрагменту
    connect(netRepository, &AppNetRepository::listenGroups, this, &SearchGroupFragment::listenGroups);
}
// деструктор
SearchGroupFragment::~SearchGroupFragment() {
    delete netRepository;
}

void SearchGroupFragment::listenGroups(DataWrapper<GroupList> wrapper) {
    // метод вызовется когда netRepository даст сигнал о загруженных группах
}
```
Отлично, у нас есть новый объект в классе экрана. Этот объект на каждый метод апи имеет один метод и один сигнал, метод инициализирует запрос, а сигнал сообщает экрану, когда запрос выполнен.
Начинаем запрос:
```cpp
netRepository->searchGroups("309С");
```
Теперь репозиторий создает запрос и отправляет его, а затем ожидает ответа. Когда к нему приходит ответ от выпускает сигнал соответствующий этому методу. В коментариях *AppNetRepository* есть описание всех методов и сигналов которые нужны для получения их ответа.
```cpp
/**
 * @brief searchGroups
 *
 * Поиск группы по части названия.
 * Ответ приходит в: signal listenGroups
 *
 * @param groupName часть названия
 */
void searchGroups(QString groupName);
```

---
## Codestyle
Небольшие пожелания по стилю кода.
Названия переменных пишутся с маленькой буквы, а новые слова разделяются капсом.
```cpp
int handlerIndex = -1;
```
Названия классов идут с большой буквы, а слова опять разделяются капсом. Также классы экранов должны заканчиваться на ..Fragment, а названия кастомных виджетов должны заканчиваться на ..Widget.
```cpp
class SplashFragment {}  // экран сплэш
class GroupItemWidtet {}  // виджет отображающий группу
```
Зоны видимости в классе будет сортировать от самой закрытой, до самой открытой. Если нет приватных переменных, то модификатор не пишется. В основном все переменные отвечающие за состояние экрана должны быть приватными. И на примере ниже видно расположение скобок. открывающая скобка идет на одной строке с названием класса или метода. (Qt Creator подсказывает по другому, но убрать лишний энтер не сложно)
```cpp
class TestFragment: public BaseFragment {
    Q_OBJECT
private:
    int privateParam = 0;
protected:
    int protecredParam = 0;
public:
    TestFragment();
    ~TestFragment();
};
```
И последний момент. Когда мы создаем экран динамически, с помощью виджетов, у нас создается большая путаница. Сложно разделять между собой элементы экрана и как-то с ними потом работать. Мы будем выделять элементы настройки одного виджета в один небольшой блок и сверху писать коментарий, показывающий что это.
Например, экран с лэйблом "hello world". Создаем два лэйаута, которые находятся друг в друге, и выделяем их в один блок. Далее добавляем лэйбл и кладем его в ранее созданный лэйаут. Таким образом у нас вышло два блока с кодом, обозначенных коментариями.
```cpp
TestFragment::TestFragment() {
    // контейнер хранящий текст
    QVBoxLayout *mainVLayout = new QVBoxLayout;
    QHBoxLayout *mainHLayout = new QHBoxLayout;
    mainHLayout->setAlignment(Qt::AlignCenter);
    mainVLayout->addLayout(mainHLayout);
    mainVLayout->setAlignment(Qt::AlignCenter);

    // тестовый лэйбл
    QLabel * testText = new QLabel("hello world");
    mainHLayout->addWidget(testText);

    this->setLayout(mainVLayout);
}
```
