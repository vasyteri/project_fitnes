/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabUserData;
    QVBoxLayout *verticalLayout_UserData;
    QLabel *userInfoLabel;
    QLineEdit *heightLineEdit;
    QLineEdit *weightLineEdit;
    QPushButton *submitUserDataButton;
    QWidget *tabProducts;
    QVBoxLayout *verticalLayout_Products;
    QLineEdit *searchLineEdit;
    QPushButton *searchButton;
    QPushButton *showAllProductsButton;
    QTableView *searchResultsTableView;
    QPushButton *addToCartButton;
    QWidget *tabCart;
    QVBoxLayout *verticalLayout_Cart;
    QTableView *cartTableView;
    QPushButton *removeFromCartButton;
    QLabel *totalCaloriesLabel;
    QLabel *totalProteinsLabel;
    QLabel *totalFatsLabel;
    QLabel *totalCarbsLabel;
    QLabel *dailyPercentageLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabUserData = new QWidget();
        tabUserData->setObjectName("tabUserData");
        verticalLayout_UserData = new QVBoxLayout(tabUserData);
        verticalLayout_UserData->setObjectName("verticalLayout_UserData");
        userInfoLabel = new QLabel(tabUserData);
        userInfoLabel->setObjectName("userInfoLabel");

        verticalLayout_UserData->addWidget(userInfoLabel);

        heightLineEdit = new QLineEdit(tabUserData);
        heightLineEdit->setObjectName("heightLineEdit");

        verticalLayout_UserData->addWidget(heightLineEdit);

        weightLineEdit = new QLineEdit(tabUserData);
        weightLineEdit->setObjectName("weightLineEdit");

        verticalLayout_UserData->addWidget(weightLineEdit);

        submitUserDataButton = new QPushButton(tabUserData);
        submitUserDataButton->setObjectName("submitUserDataButton");

        verticalLayout_UserData->addWidget(submitUserDataButton);

        tabWidget->addTab(tabUserData, QString());
        tabProducts = new QWidget();
        tabProducts->setObjectName("tabProducts");
        verticalLayout_Products = new QVBoxLayout(tabProducts);
        verticalLayout_Products->setObjectName("verticalLayout_Products");
        searchLineEdit = new QLineEdit(tabProducts);
        searchLineEdit->setObjectName("searchLineEdit");

        verticalLayout_Products->addWidget(searchLineEdit);

        searchButton = new QPushButton(tabProducts);
        searchButton->setObjectName("searchButton");

        verticalLayout_Products->addWidget(searchButton);

        showAllProductsButton = new QPushButton(tabProducts);
        showAllProductsButton->setObjectName("showAllProductsButton");

        verticalLayout_Products->addWidget(showAllProductsButton);

        searchResultsTableView = new QTableView(tabProducts);
        searchResultsTableView->setObjectName("searchResultsTableView");

        verticalLayout_Products->addWidget(searchResultsTableView);

        addToCartButton = new QPushButton(tabProducts);
        addToCartButton->setObjectName("addToCartButton");

        verticalLayout_Products->addWidget(addToCartButton);

        tabWidget->addTab(tabProducts, QString());
        tabCart = new QWidget();
        tabCart->setObjectName("tabCart");
        verticalLayout_Cart = new QVBoxLayout(tabCart);
        verticalLayout_Cart->setObjectName("verticalLayout_Cart");
        cartTableView = new QTableView(tabCart);
        cartTableView->setObjectName("cartTableView");

        verticalLayout_Cart->addWidget(cartTableView);

        removeFromCartButton = new QPushButton(tabCart);
        removeFromCartButton->setObjectName("removeFromCartButton");

        verticalLayout_Cart->addWidget(removeFromCartButton);

        totalCaloriesLabel = new QLabel(tabCart);
        totalCaloriesLabel->setObjectName("totalCaloriesLabel");

        verticalLayout_Cart->addWidget(totalCaloriesLabel);

        totalProteinsLabel = new QLabel(tabCart);
        totalProteinsLabel->setObjectName("totalProteinsLabel");

        verticalLayout_Cart->addWidget(totalProteinsLabel);

        totalFatsLabel = new QLabel(tabCart);
        totalFatsLabel->setObjectName("totalFatsLabel");

        verticalLayout_Cart->addWidget(totalFatsLabel);

        totalCarbsLabel = new QLabel(tabCart);
        totalCarbsLabel->setObjectName("totalCarbsLabel");

        verticalLayout_Cart->addWidget(totalCarbsLabel);

        dailyPercentageLabel = new QLabel(tabCart);
        dailyPercentageLabel->setObjectName("dailyPercentageLabel");

        verticalLayout_Cart->addWidget(dailyPercentageLabel);

        tabWidget->addTab(tabCart, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200 \320\272\320\260\320\273\320\276\321\200\320\270\320\271", nullptr));
        heightLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\262\320\260\321\210 \321\200\320\276\321\201\321\202", nullptr));
        weightLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\262\320\260\321\210 \320\262\320\265\321\201", nullptr));
        submitUserDataButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabUserData), QCoreApplication::translate("MainWindow", "\320\224\320\260\320\275\320\275\321\213\320\265", nullptr));
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272 \320\277\321\200\320\276\320\264\321\203\320\272\321\202\320\260", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "\320\230\321\201\320\272\320\260\321\202\321\214", nullptr));
        showAllProductsButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\262\321\201\320\265 \320\277\321\200\320\276\320\264\321\203\320\272\321\202\321\213", nullptr));
        addToCartButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\262 \320\272\320\276\321\200\320\267\320\270\320\275\321\203", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabProducts), QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\264\321\203\320\272\321\202\321\213", nullptr));
        removeFromCartButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\270\320\267 \320\272\320\276\321\200\320\267\320\270\320\275\321\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabCart), QCoreApplication::translate("MainWindow", "\320\232\320\276\321\200\320\267\320\270\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
