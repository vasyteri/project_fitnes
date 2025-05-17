#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "productdatabase.h"
#include "user.h"
#include "shoppingcart.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onUserDataSubmitted();
    void onSearchClicked();
    void onAddToCartClicked();
    void onRemoveFromCartClicked();
    void onShowAllProductsClicked();
    void onCartItemSelected(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    ProductDatabase database;
    User user;
    ShoppingCart cart;
    QStandardItemModel *searchResultsModel;
    QStandardItemModel *cartModel;

    void showUserInfo();
    void updateCartSummary();
    void showWelcomeScreen();
    void showMainScreen();
    void loadDatabase();
};

#endif // MAINWINDOW_H
