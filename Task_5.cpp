#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void displayImage(const Mat& image, const string& windowName) {
    imshow(windowName, image);
    waitKey(0);  // Wait for a keystroke in the window
    destroyWindow(windowName);
}

void applyGrayscale(Mat& image) {
    cvtColor(image, image, COLOR_BGR2GRAY);
}

void applyBlur(Mat& image) {
    GaussianBlur(image, image, Size(15, 15), 0);
}

void applySharpen(Mat& image) {
    Mat kernel = (Mat_<float>(3,3) <<
                   0, -1,  0,
                  -1,  5, -1,
                   0, -1,  0);
    filter2D(image, image, -1, kernel);
}

void adjustBrightnessContrast(Mat& image, double alpha, int beta) {
    for (int y = 0; y < image.rows; y++) {
        for (int x = 0; x < image.cols; x++) {
            for (int c = 0; c < image.channels(); c++) {
                image.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(alpha * image.at<Vec3b>(y, x)[c] + beta);
            }
        }
    }
}

void cropImage(Mat& image, Rect roi) {
    image = image(roi);
}

void resizeImage(Mat& image, int width, int height) {
    resize(image, image, Size(width, height));
}

int main() {
    Mat image;
    string imagePath;
    int choice;

    while (true) {
        cout << "1. Load Image" << endl;
        cout << "2. Display Image" << endl;
        cout << "3. Apply Grayscale Filter" << endl;
        cout << "4. Apply Blur Filter" << endl;
        cout << "5. Apply Sharpen Filter" << endl;
        cout << "6. Adjust Brightness/Contrast" << endl;
        cout << "7. Crop Image" << endl;
        cout << "8. Resize Image" << endl;
        cout << "9. Save Image" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the path of the image: ";
                cin >> imagePath;
                image = imread(imagePath);
                if (image.empty()) {
                    cout << "Error: Could not load image." << endl;
                } else {
                    cout << "Image loaded successfully." << endl;
                }
                break;
            case 2:
                if (image.empty()) {
                    cout << "No image loaded." << endl;
                } else {
                    displayImage(image, "Loaded Image");
                }
                break;
            case 3:
                if (image.empty()) {
                    cout << "No image loaded." << endl;
                } else {
                    applyGrayscale(image);
                    cout << "Grayscale filter applied." << endl;
                }
                break;
            case 4:
                if (image.empty()) {
                    cout << "No image loaded." << endl;
                } else {
                    applyBlur(image);
                    cout << "Blur filter applied." << endl;
                }
                break;
            case 5:
                if (image.empty()) {
                    cout << "No image loaded." << endl;
                } else {
                    applySharpen(image);
                    cout << "Sharpen filter applied." << endl;
                }
                break;
            case 6:
                if (image.empty()) {
                    cout << "No image loaded." << endl;
                } else {
                    double alpha;
                    int beta;
                    cout << "Enter alpha (contrast, 1.0-3.0): ";
                    cin >> alpha;
                    cout << "Enter beta (brightness, 0-100): ";
                    cin >> beta;
                    adjustBrightnessContrast(image, alpha, beta);
                    cout << "Brightness/Contrast adjusted." << endl;
                }
                break;
            case 7:
                if (image.empty()) {
                    cout << "No image loaded." << endl;
                } else {
                    int x, y, width, height;
                    cout << "Enter x, y, width, height for cropping: ";
                    cin >> x >> y >> width >> height;
                    cropImage(image, Rect(x, y, width, height));
                    cout << "Image cropped." << endl;
                }
                break;
            case 8:
                if (image.empty()) {
                    cout << "No image loaded." << endl;
                } else {
                    int width, height;
                    cout << "Enter new width and height: ";
                    cin >> width >> height;
                    resizeImage(image, width, height);
                    cout << "Image resized." << endl;
                }
                break;
            case 9:
                if (image.empty()) {
                    cout << "No image loaded." << endl;
                } else {
                    string savePath;
                    cout << "Enter path to save the image: ";
                    cin >> savePath;
                    imwrite(savePath, image);
                    cout << "Image saved successfully." << endl;
                }
                break;
            case 10:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
