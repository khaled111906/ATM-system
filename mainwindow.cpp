#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Main menu connections
    connect(ui->btnAdmin, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->adminloginpage);
    });
    connect(ui->btnCustomer, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->customerloginpage);
    });
    connect(ui->btnExit, &QPushButton::clicked, this, &MainWindow::close);

    // Login page connections
    connect(ui->btnadminlogin, &QPushButton::clicked, this, &MainWindow::handleAdminLogin);
    connect(ui->btnloginacc, &QPushButton::clicked, this, &MainWindow::handleCustomerLogin);

    // Admin main menu connections
    connect(ui->adminbtn1, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->addcustomerpage);
    });
    connect(ui->adminbtn2, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->removecustomerpage);
    });
    connect(ui->adminbtn3, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->mainmenu);
    });

    // Customer main menu connections
    connect(ui->custbtn1, &QPushButton::clicked, [this]() {
        Customer* customer = atm.getCurrentCustomer();
        if (customer) {
            ui->checkingBalanceLabel->setText(QString("Checking Balance: $%1").arg(customer->getCheckingBalance(), 0, 'f', 2));
            ui->stackedWidget->setCurrentWidget(ui->checkingaccountpage);
        }
    });
    connect(ui->custbtn2, &QPushButton::clicked, [this]() {
        Customer* customer = atm.getCurrentCustomer();
        if (customer) {
            ui->savingsBalanceLabel->setText(QString("Savings Balance: $%1").arg(customer->getSavingsBalance(), 0, 'f', 2));
            ui->stackedWidget->setCurrentWidget(ui->savingsaccountpage);
        }
    });
    connect(ui->custbtn3, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->mainmenu);
    });

    // Add customer page connection
    connect(ui->addCustomerBtn, &QPushButton::clicked, [this]() {
        std::string id = ui->idLineEdit->text().toStdString();
        std::string name = ui->nameLineEdit->text().toStdString();
        std::string pw = ui->pwLineEdit->text().toStdString();
        double cb = ui->checkingLineEdit->text().toDouble();
        double sb = ui->savingsLineEdit->text().toDouble();
        Customer newCustomer(id, pw, name, cb, sb);
        atm.addCustomer(newCustomer);
        QMessageBox::information(this, "Success", "Customer added");
        ui->stackedWidget->setCurrentWidget(ui->adminmainmenu);
    });

    // Remove customer page connection
    connect(ui->removeCustomerBtn, &QPushButton::clicked, [this]() {
        std::string id = ui->removeIDLineEdit->text().toStdString();
        atm.removeCustomer(id);
        QMessageBox::information(this, "Success", "Customer removed");
        ui->stackedWidget->setCurrentWidget(ui->adminmainmenu);
    });

    // Checking account page connections
    connect(ui->checkingDepositBtn, &QPushButton::clicked, [this]() {
        Customer* customer = atm.getCurrentCustomer();
        if (customer) {
            double amount = ui->checkingAmountLineEdit->text().toDouble();
            if (amount > 0) {
                customer->deposit(customer->getCheckingBalance(), amount);
                ui->checkingBalanceLabel->setText(QString("Checking Balance: $%1").arg(customer->getCheckingBalance(), 0, 'f', 2));
            } else {
                QMessageBox::warning(this, "Error", "Invalid amount");
            }
        }
    });
    connect(ui->checkingWithdrawBtn, &QPushButton::clicked, [this]() {
        Customer* customer = atm.getCurrentCustomer();
        if (customer) {
            double amount = ui->checkingAmountLineEdit->text().toDouble();
            if (amount > 0 && amount <= customer->getCheckingBalance()) {
                customer->withdraw(customer->getCheckingBalance(), amount);
                ui->checkingBalanceLabel->setText(QString("Checking Balance: $%1").arg(customer->getCheckingBalance(), 0, 'f', 2));
            } else {
                QMessageBox::warning(this, "Error", "Invalid amount or insufficient funds");
            }
        }
    });
    connect(ui->checkingTransferBtn, &QPushButton::clicked, [this]() {
        Customer* customer = atm.getCurrentCustomer();
        if (customer) {
            double amount = ui->checkingAmountLineEdit->text().toDouble();
            if (amount > 0 && amount <= customer->getCheckingBalance()) {
                customer->transfer(customer->getCheckingBalance(), customer->getSavingsBalance(), amount);
                ui->checkingBalanceLabel->setText(QString("Checking Balance: $%1").arg(customer->getCheckingBalance(), 0, 'f', 2));
            } else {
                QMessageBox::warning(this, "Error", "Invalid amount or insufficient funds");
            }
        }
    });
    connect(ui->checkingBackBtn, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->customermainmenu);
    });

    // Savings account page connections
    connect(ui->savingsDepositBtn, &QPushButton::clicked, [this]() {
        Customer* customer = atm.getCurrentCustomer();
        if (customer) {
            double amount = ui->savingsAmountLineEdit->text().toDouble();
            if (amount > 0) {
                customer->deposit(customer->getSavingsBalance(), amount);
                ui->savingsBalanceLabel->setText(QString("Savings Balance: $%1").arg(customer->getSavingsBalance(), 0, 'f', 2));
            } else {
                QMessageBox::warning(this, "Error", "Invalid amount");
            }
        }
    });
    connect(ui->savingsBackBtn, &QPushButton::clicked, [this]() {
        ui->stackedWidget->setCurrentWidget(ui->customermainmenu);
    });
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::handleAdminLogin() {
    QString id = ui->adminIDLineEdit->text();
    QString pw = ui->passwordLineEdit_2->text();
    if (atm.loginAdmin(id.toStdString(), pw.toStdString())) {
        ui->stackedWidget->setCurrentWidget(ui->adminmainmenu);
    } else {
        QMessageBox::warning(this, "Login Failed", "Incorrect ID or Password");
    }
}

void MainWindow::handleCustomerLogin() {
    QString id = ui->accountIDLineEdit->text();
    QString pw = ui->accpassLineEdit->text();
    if (atm.loginCustomer(id.toStdString(), pw.toStdString())) {
        ui->stackedWidget->setCurrentWidget(ui->customermainmenu);
    } else {
        QMessageBox::warning(this, "Login Failed", "Incorrect ID or Password");
    }
}
