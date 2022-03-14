#ifndef LIBRARYITEMWIDGET_H
#define LIBRARYITEMWIDGET_H

#include <ui/widgets/cardwidget.h>

#include <data/models/library/librarymodel.h>



class LibraryItemWidget: public CardWidget {
    Q_OBJECT
public:
    LibraryItemWidget(LibraryModel model);
};

#endif // LIBRARYITEMWIDGET_H
