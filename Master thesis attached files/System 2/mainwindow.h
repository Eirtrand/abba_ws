#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTime>
#include <QTimer>


#include "segmentation_techniques.h"
#include "hole_detection.h"
#include "growth_detection.h"
#include "colorspaces.h"
#include "tweaking.h"
#include "image_enhancement.h"

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

namespace Ui {
class MainWindow;
}

enum Color_Space { COLOR_NONE=0,X,Y,LUMINANCE,RED,GREEN,BLUE,
                    X2,Y2,LUMINANCE2,LAB,L,A,B};
enum Thresholding_Method {NO_THRESH_MODE=0,SOBEL,SCHARR,LAPLACIAN,OTSU,THRESHOLDING,ADAPTIVE_THRESHOLDING};
enum Mode { NO_MODE=0,HOLE_DETECTION,GROWTH_DETECTION };


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void process_frame(cv::Mat b4_tweak_input_image);

    void runCamera();

    void runImage();

    void runVideo();

private:
    void hide_all_seg_boxes();

private slots:
    void on_Sobel_clicked();

    void on_Local_Sobel_horizontalSlider_valueChanged(int value);

    void on_Scharr_clicked();

    void on_Local_Scharr_horizontalSlider_valueChanged(int value);

    void on_Laplacian_clicked();

    void on_Laplacian_sub_image_horizontalSlider_valueChanged(int value);

    void on_Otsu_clicked();

    void on_Local_Otsu_horizontalSlider_valueChanged(int value);

    void on_Capture_clicked();

    void on_Local_Sobel_histogram_slider_valueChanged(int value);

    void on_Local_Scharr_histogram_slider_valueChanged(int value);

    void on_Laplacian_histogram_slider_valueChanged(int value);

    void on_Thresholding_clicked();

    void on_Adaptive_Thresholding_clicked();

    void on_No_Mode_clicked();

    void on_Hole_Detection_clicked();

    void on_Growth_detection_clicked();

    void on_y_clicked();

    void on_x_clicked();

    void on_Y_clicked();

    void on_Red_clicked();

    void on_Green_clicked();

    void on_Blue_clicked();

    void on_x2_clicked();

    void on_y2_clicked();

    void on_Y2_clicked();

    void on_Lab_clicked();

    void on_L_clicked();

    void on_a_clicked();

    void on_b_clicked();

    void on_Dilation_horizontalSlider_valueChanged(int value);

    void on_Threshold_slider_valueChanged(int value);

    void on_Gaussian_horizontalSlider_valueChanged(int value);

    void on_Local_Sobel_dx_slider_valueChanged(int value);

    void on_Local_Sobel_dy_slider_valueChanged(int value);

    void on_Local_Sobel_kernel_slider_valueChanged(int value);

    void on_Laplacian_kernel_slider_valueChanged(int value);

    void on_Adaptive_Thresholding_kernel_slider_valueChanged(int value);

    void on_Adaptive_Thresholding_C_slider_valueChanged(int value);

    void on_Capture_clean_net_pushButton_clicked();

    void on_Webcam_source_radioButton_clicked();

    void on_Image_source_radioButton_clicked();

    void on_Video_source_radioButton_clicked();

    void on_actionPause_triggered();

    void on_actionDont_Process_triggered();

    void on_No_Segmentation_Mode_clicked();

    void on_No_Color_Mode_clicked();

    void display_frame(cv::Mat processed_image, cv::Mat segmented_image, cv::Mat hole_detected_image);

private:
    Ui::MainWindow *ui;
    QTimer* tmrTimer;
    cv::VideoCapture capWebcam; 
    bool PAUSE;

    cv::Mat image;
    cv::Mat image_from_file;

    int Local_Sobel_numberofSubImages;
    int Local_Sobel_hist_percentile;
    int Local_Sobel_dx;
    int Local_Sobel_dy;
    int Local_Sobel_kernel_size;
    int Laplacian_numberofSubImages;
    int Laplacian_hist_percentile;
    int Laplacian_kernel_size;
    int Local_Scharr_numberofSubImages;
    int Local_Scharr_hist_percentile;
    int Local_Otsu_numberofSubImages;
    int Naive_threshold;

    int Dilation_iterations;
    int Gaussian_kernel_size;
    int Adaptive_Thresholding_kernel_size;
    int Adaptive_thresholding_C;

    double Percentage_foreground_clean_net;
    bool capture_clean_net;
    bool capture;

    QString fileName;
    double video_file_FPS;

    Color_Space cspace;
    Thresholding_Method thresh_met;
    Mode mode;

};

#endif // MAINWINDOW_H
