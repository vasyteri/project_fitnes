#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    searchResultsModel = new QStandardItemModel(this);
    cartModel = new QStandardItemModel(this);

    ui->searchResultsTableView->setModel(searchResultsModel);
    ui->cartTableView->setModel(cartModel);

    connect(ui->submitUserDataButton, &QPushButton::clicked, this, &MainWindow::onUserDataSubmitted);
    connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::onSearchClicked);
    connect(ui->addToCartButton, &QPushButton::clicked, this, &MainWindow::onAddToCartClicked);
    connect(ui->removeFromCartButton, &QPushButton::clicked, this, &MainWindow::onRemoveFromCartClicked);
    connect(ui->showAllProductsButton, &QPushButton::clicked, this, &MainWindow::onShowAllProductsClicked);
    connect(ui->cartTableView->selectionModel(), &QItemSelectionModel::selectionChanged,
            [this](const QItemSelection &selected, const QItemSelection &deselected) {
                Q_UNUSED(deselected);
                if (!selected.indexes().isEmpty()) {
                    onCartItemSelected(selected.indexes().first());
                }
            });

    loadDatabase();
    showWelcomeScreen();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::loadDatabase() {
    if (!database.loadFromFile("products.csv")) {
        QMessageBox::warning(this, "Ошибка", "Не удалось загрузить базу продуктов. Будет создана пустая база.");
    }
}

void MainWindow::showWelcomeScreen() {
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::showMainScreen() {
    ui->stackedWidget->setCurrentIndex(1);
    showUserInfo();
}

void MainWindow::showUserInfo() {
    ui->userInfoLabel->setText(QString("Рост: %1 см, Вес: %2 кг\nСуточная норма: %3 ккал")
                              .arg(user.getHeight())
                              .arg(user.getWeight())
                              .arg(user.getDailyCalories()));
}

void MainWindow::onUserDataSubmitted() {
    bool heightOk, weightOk;
    double height = ui->heightLineEdit->text().toDouble(&heightOk);
    double weight = ui->weightLineEdit->text().toDouble(&weightOk);

    if (!heightOk || !weightOk || height <= 0 || weight <= 0) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите корректные значения роста и веса.");
        return;
    }

    user.setHeight(height);
    user.setWeight(weight);
    user.calculateDailyCalories();

    showMainScreen();
}

void MainWindow::onSearchClicked() {
    QString query = ui->searchLineEdit->text().trimmed();
    if (query.isEmpty()) {
        QMessageBox::information(this, "Информация", "Пожалуйста, введите название продукта для поиска.");
        return;
    }

    auto results = database.searchProduct(query.toStdString());
    searchResultsModel->clear();
    searchResultsModel->setHorizontalHeaderLabels({"Название", "Калории", "Белки", "Жиры", "Углеводы"});

    for (const auto& product : results) {
        QList<QStandardItem*> items;
        items.append(new QStandardItem(QString::fromStdString(product.getName())));
        items.append(new QStandardItem(QString::number(product.getCalories())));
        items.append(new QStandardItem(QString::number(product.getProteins())));
        items.append(new QStandardItem(QString::number(product.getFats())));
        items.append(new QStandardItem(QString::number(product.getCarbs())));
        searchResultsModel->appendRow(items);
    }

    if (results.empty()) {
        QMessageBox::information(this, "Результаты поиска", "Продукты не найдены.");
    }
}


void MainWindow::onAddToCartClicked() {
    QModelIndexList selected = ui->searchResultsTableView->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, выберите продукт из списка результатов.");
        return;
    }

    QString name = searchResultsModel->item(selected.first().row(), 0)->text();
    double calories = searchResultsModel->item(selected.first().row(), 1)->text().toDouble();
    double proteins = searchResultsModel->item(selected.first().row(), 2)->text().toDouble();
    double fats = searchResultsModel->item(selected.first().row(), 3)->text().toDouble();
    double carbs = searchResultsModel->item(selected.first().row(), 4)->text().toDouble();

    Product product(name.toStdString(), calories, proteins, fats, carbs);
    cart.addProduct(product);

    updateCartSummary();
}

void MainWindow::onRemoveFromCartClicked() {
    QModelIndexList selected = ui->cartTableView->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, выберите продукт из корзины.");
        return;
    }

    cart.removeProduct(selected.first().row());
    updateCartSummary();
}

void MainWindow::onShowAllProductsClicked() {
    auto allProducts = database.getAllProducts();
    searchResultsModel->clear();
    searchResultsModel->setHorizontalHeaderLabels({"Название", "Калории", "Белки", "Жиры", "Углеводы"});

    for (const auto& product : allProducts) {
        QList<QStandardItem*> items;
        items.append(new QStandardItem(QString::fromStdString(product.getName())));
        items.append(new QStandardItem(QString::number(product.getCalories())));
        items.append(new QStandardItem(QString::number(product.getProteins())));
        items.append(new QStandardItem(QString::number(product.getFats())));
        items.append(new QStandardItem(QString::number(product.getCarbs())));
        searchResultsModel->appendRow(items);
    }
}

void MainWindow::onCartItemSelected(const QModelIndex &index) {
    // Можно добавить дополнительную информацию о выбранном продукте
    Q_UNUSED(index);
}

void MainWindow::updateCartSummary() {
    cartModel->clear();
    cartModel->setHorizontalHeaderLabels({"Название", "Калории", "Белки", "Жиры", "Углеводы"});

    for (const auto& product : cart.getItems()) {
        QList<QStandardItem*> items;
        items.append(new QStandardItem(QString::fromStdString(product.getName())));
        items.append(new QStandardItem(QString::number(product.getCalories())));
        items.append(new QStandardItem(QString::number(product.getProteins())));
        items.append(new QStandardItem(QString::number(product.getFats())));
        items.append(new QStandardItem(QString::number(product.getCarbs())));
        cartModel->appendRow(items);
    }

    ui->totalCaloriesLabel->setText(QString::number(cart.getTotalCalories()));
    ui->totalProteinsLabel->setText(QString::number(cart.getTotalProteins()));
    ui->totalFatsLabel->setText(QString::number(cart.getTotalFats()));
    ui->totalCarbsLabel->setText(QString::number(cart.getTotalCarbs()));

    double percentage = (user.getDailyCalories() > 0) ?
        (cart.getTotalCalories() / user.getDailyCalories() * 100) : 0;
    ui->dailyPercentageLabel->setText(QString("%1%").arg(percentage, 0, 'f', 1));
}
