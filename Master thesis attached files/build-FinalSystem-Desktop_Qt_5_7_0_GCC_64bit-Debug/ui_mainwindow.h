/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionPause;
    QAction *actionDont_Process;
    QWidget *centralWidget;
    QLabel *label;
    QGroupBox *Modes_groupbox;
    QPushButton *Capture_clean_net_pushButton;
    QGroupBox *Growth_box_2;
    QPlainTextEdit *growth_plainText;
    QRadioButton *Growth_detection;
    QRadioButton *Hole_Detection;
    QRadioButton *No_Mode;
    QGroupBox *Input_Source_groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_13;
    QRadioButton *Webcam_source_radioButton;
    QRadioButton *Image_source_radioButton;
    QRadioButton *Video_source_radioButton;
    QGroupBox *choose_view_groupBox;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *View_input;
    QRadioButton *View_color_space;
    QRadioButton *View_segmented;
    QRadioButton *View_damage_detection;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *Gradient_equalizer_checkBox;
    QCheckBox *Morphological_gradient_equalizer_checkBox;
    QCheckBox *Morphological_sharpen_checkBox;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *Dilation_checkBox;
    QGroupBox *Dilation_groupBox;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_12;
    QSlider *Dilation_horizontalSlider;
    QLCDNumber *Dilation_lcdNumber;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *Gaussian_checkBox;
    QGroupBox *Gaussian_smoothing_groupBox;
    QWidget *layoutWidget_8;
    QHBoxLayout *horizontalLayout_15;
    QSlider *Gaussian_horizontalSlider;
    QLCDNumber *Gaussian_lcdNumber;
    QGroupBox *time_spent_box;
    QPlainTextEdit *Total_time_spent;
    QPushButton *Capture;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1402, 350);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 300));
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName(QStringLiteral("actionPause"));
        actionDont_Process = new QAction(MainWindow);
        actionDont_Process->setObjectName(QStringLiteral("actionDont_Process"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(5, 100, 111, 61));
        Modes_groupbox = new QGroupBox(centralWidget);
        Modes_groupbox->setObjectName(QStringLiteral("Modes_groupbox"));
        Modes_groupbox->setGeometry(QRect(220, 0, 501, 45));
        Capture_clean_net_pushButton = new QPushButton(Modes_groupbox);
        Capture_clean_net_pushButton->setObjectName(QStringLiteral("Capture_clean_net_pushButton"));
        Capture_clean_net_pushButton->setGeometry(QRect(400, 16, 94, 23));
        Growth_box_2 = new QGroupBox(Modes_groupbox);
        Growth_box_2->setObjectName(QStringLiteral("Growth_box_2"));
        Growth_box_2->setGeometry(QRect(300, 10, 95, 31));
        Growth_box_2->setAlignment(Qt::AlignCenter);
        growth_plainText = new QPlainTextEdit(Growth_box_2);
        growth_plainText->setObjectName(QStringLiteral("growth_plainText"));
        growth_plainText->setGeometry(QRect(4, 12, 137, 53));
        growth_plainText->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        growth_plainText->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        Growth_detection = new QRadioButton(Modes_groupbox);
        Growth_detection->setObjectName(QStringLiteral("Growth_detection"));
        Growth_detection->setGeometry(QRect(190, 20, 107, 17));
        Hole_Detection = new QRadioButton(Modes_groupbox);
        Hole_Detection->setObjectName(QStringLiteral("Hole_Detection"));
        Hole_Detection->setGeometry(QRect(80, 20, 111, 17));
        No_Mode = new QRadioButton(Modes_groupbox);
        No_Mode->setObjectName(QStringLiteral("No_Mode"));
        No_Mode->setGeometry(QRect(12, 22, 65, 17));
        No_Mode->setChecked(true);
        Input_Source_groupBox = new QGroupBox(centralWidget);
        Input_Source_groupBox->setObjectName(QStringLiteral("Input_Source_groupBox"));
        Input_Source_groupBox->setGeometry(QRect(0, 0, 201, 45));
        layoutWidget = new QWidget(Input_Source_groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 182, 19));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        Webcam_source_radioButton = new QRadioButton(layoutWidget);
        Webcam_source_radioButton->setObjectName(QStringLiteral("Webcam_source_radioButton"));
        Webcam_source_radioButton->setChecked(true);

        horizontalLayout_13->addWidget(Webcam_source_radioButton);

        Image_source_radioButton = new QRadioButton(layoutWidget);
        Image_source_radioButton->setObjectName(QStringLiteral("Image_source_radioButton"));

        horizontalLayout_13->addWidget(Image_source_radioButton);

        Video_source_radioButton = new QRadioButton(layoutWidget);
        Video_source_radioButton->setObjectName(QStringLiteral("Video_source_radioButton"));

        horizontalLayout_13->addWidget(Video_source_radioButton);

        choose_view_groupBox = new QGroupBox(centralWidget);
        choose_view_groupBox->setObjectName(QStringLiteral("choose_view_groupBox"));
        choose_view_groupBox->setGeometry(QRect(0, 50, 351, 41));
        layoutWidget1 = new QWidget(choose_view_groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 333, 19));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        View_input = new QRadioButton(layoutWidget1);
        View_input->setObjectName(QStringLiteral("View_input"));
        View_input->setChecked(true);

        horizontalLayout_2->addWidget(View_input);

        View_color_space = new QRadioButton(layoutWidget1);
        View_color_space->setObjectName(QStringLiteral("View_color_space"));

        horizontalLayout_2->addWidget(View_color_space);

        View_segmented = new QRadioButton(layoutWidget1);
        View_segmented->setObjectName(QStringLiteral("View_segmented"));

        horizontalLayout_2->addWidget(View_segmented);

        View_damage_detection = new QRadioButton(layoutWidget1);
        View_damage_detection->setObjectName(QStringLiteral("View_damage_detection"));

        horizontalLayout_2->addWidget(View_damage_detection);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(720, 0, 561, 91));
        layoutWidget2 = new QWidget(groupBox_3);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 18, 531, 67));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        Gradient_equalizer_checkBox = new QCheckBox(layoutWidget2);
        Gradient_equalizer_checkBox->setObjectName(QStringLiteral("Gradient_equalizer_checkBox"));

        verticalLayout_2->addWidget(Gradient_equalizer_checkBox);

        Morphological_gradient_equalizer_checkBox = new QCheckBox(layoutWidget2);
        Morphological_gradient_equalizer_checkBox->setObjectName(QStringLiteral("Morphological_gradient_equalizer_checkBox"));

        verticalLayout_2->addWidget(Morphological_gradient_equalizer_checkBox);

        Morphological_sharpen_checkBox = new QCheckBox(layoutWidget2);
        Morphological_sharpen_checkBox->setObjectName(QStringLiteral("Morphological_sharpen_checkBox"));

        verticalLayout_2->addWidget(Morphological_sharpen_checkBox);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        Dilation_checkBox = new QCheckBox(layoutWidget2);
        Dilation_checkBox->setObjectName(QStringLiteral("Dilation_checkBox"));
        Dilation_checkBox->setChecked(true);

        verticalLayout_4->addWidget(Dilation_checkBox);

        Dilation_groupBox = new QGroupBox(layoutWidget2);
        Dilation_groupBox->setObjectName(QStringLiteral("Dilation_groupBox"));
        layoutWidget3 = new QWidget(Dilation_groupBox);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(4, 12, 141, 25));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        Dilation_horizontalSlider = new QSlider(layoutWidget3);
        Dilation_horizontalSlider->setObjectName(QStringLiteral("Dilation_horizontalSlider"));
        Dilation_horizontalSlider->setMinimum(1);
        Dilation_horizontalSlider->setMaximum(10);
        Dilation_horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_12->addWidget(Dilation_horizontalSlider);

        Dilation_lcdNumber = new QLCDNumber(layoutWidget3);
        Dilation_lcdNumber->setObjectName(QStringLiteral("Dilation_lcdNumber"));
        Dilation_lcdNumber->setProperty("intValue", QVariant(1));

        horizontalLayout_12->addWidget(Dilation_lcdNumber);


        verticalLayout_4->addWidget(Dilation_groupBox);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        Gaussian_checkBox = new QCheckBox(layoutWidget2);
        Gaussian_checkBox->setObjectName(QStringLiteral("Gaussian_checkBox"));

        verticalLayout_3->addWidget(Gaussian_checkBox);

        Gaussian_smoothing_groupBox = new QGroupBox(layoutWidget2);
        Gaussian_smoothing_groupBox->setObjectName(QStringLiteral("Gaussian_smoothing_groupBox"));
        layoutWidget_8 = new QWidget(Gaussian_smoothing_groupBox);
        layoutWidget_8->setObjectName(QStringLiteral("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(4, 12, 141, 25));
        horizontalLayout_15 = new QHBoxLayout(layoutWidget_8);
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        Gaussian_horizontalSlider = new QSlider(layoutWidget_8);
        Gaussian_horizontalSlider->setObjectName(QStringLiteral("Gaussian_horizontalSlider"));
        Gaussian_horizontalSlider->setMinimum(1);
        Gaussian_horizontalSlider->setMaximum(25);
        Gaussian_horizontalSlider->setSingleStep(2);
        Gaussian_horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_15->addWidget(Gaussian_horizontalSlider);

        Gaussian_lcdNumber = new QLCDNumber(layoutWidget_8);
        Gaussian_lcdNumber->setObjectName(QStringLiteral("Gaussian_lcdNumber"));
        Gaussian_lcdNumber->setProperty("intValue", QVariant(1));

        horizontalLayout_15->addWidget(Gaussian_lcdNumber);


        verticalLayout_3->addWidget(Gaussian_smoothing_groupBox);


        horizontalLayout->addLayout(verticalLayout_3);

        time_spent_box = new QGroupBox(centralWidget);
        time_spent_box->setObjectName(QStringLiteral("time_spent_box"));
        time_spent_box->setGeometry(QRect(500, 50, 145, 41));
        time_spent_box->setAlignment(Qt::AlignCenter);
        Total_time_spent = new QPlainTextEdit(time_spent_box);
        Total_time_spent->setObjectName(QStringLiteral("Total_time_spent"));
        Total_time_spent->setGeometry(QRect(4, 12, 137, 53));
        Total_time_spent->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        Total_time_spent->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        Capture = new QPushButton(centralWidget);
        Capture->setObjectName(QStringLiteral("Capture"));
        Capture->setGeometry(QRect(360, 60, 109, 25));
        QFont font;
        font.setPointSize(12);
        Capture->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1402, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionPause);
        menuFile->addAction(actionDont_Process);

        retranslateUi(MainWindow);
        QObject::connect(Dilation_horizontalSlider, SIGNAL(valueChanged(int)), Dilation_lcdNumber, SLOT(display(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionPause->setText(QApplication::translate("MainWindow", "Pause", 0));
        actionDont_Process->setText(QApplication::translate("MainWindow", "Do not Process", 0));
        label->setText(QString());
        Modes_groupbox->setTitle(QApplication::translate("MainWindow", "Mode", 0));
        Capture_clean_net_pushButton->setText(QApplication::translate("MainWindow", "Capture clean net", 0));
        Growth_box_2->setTitle(QApplication::translate("MainWindow", "Growth", 0));
        Growth_detection->setText(QApplication::translate("MainWindow", "Growth Detection", 0));
        Hole_Detection->setText(QApplication::translate("MainWindow", "Damage Detection", 0));
        No_Mode->setText(QApplication::translate("MainWindow", "No Mode", 0));
        Input_Source_groupBox->setTitle(QApplication::translate("MainWindow", "Input Source", 0));
        Webcam_source_radioButton->setText(QApplication::translate("MainWindow", "WebCam", 0));
        Image_source_radioButton->setText(QApplication::translate("MainWindow", "Image", 0));
        Video_source_radioButton->setText(QApplication::translate("MainWindow", "Video", 0));
        choose_view_groupBox->setTitle(QApplication::translate("MainWindow", "Choose  view", 0));
        View_input->setText(QApplication::translate("MainWindow", "Input", 0));
        View_color_space->setText(QApplication::translate("MainWindow", "Color space", 0));
        View_segmented->setText(QApplication::translate("MainWindow", "Segmented", 0));
        View_damage_detection->setText(QApplication::translate("MainWindow", "Damage detected", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Enhancement methods", 0));
        Gradient_equalizer_checkBox->setText(QApplication::translate("MainWindow", "Light gradient equalizer", 0));
        Morphological_gradient_equalizer_checkBox->setText(QApplication::translate("MainWindow", "Morphological light gradient equalizer", 0));
        Morphological_sharpen_checkBox->setText(QApplication::translate("MainWindow", "Morphological sharpen", 0));
        Dilation_checkBox->setText(QApplication::translate("MainWindow", "Dilation", 0));
        Dilation_groupBox->setTitle(QApplication::translate("MainWindow", "Number of rounds", 0));
        Gaussian_checkBox->setText(QApplication::translate("MainWindow", "Gaussian Smoothing", 0));
        Gaussian_smoothing_groupBox->setTitle(QApplication::translate("MainWindow", "Kernel size", 0));
        time_spent_box->setTitle(QApplication::translate("MainWindow", "Total time spent per image", 0));
        Capture->setText(QApplication::translate("MainWindow", "Capture", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
