#include <opencv2/opencv.hpp>

namespace ImageProcessing {

    // Typ wyliczeniowy reprezentujący kierunek obrotu
    enum class RotationDirection {
        CLOCKWISE,
        COUNTERCLOCKWISE
    };

    // Struktura reprezentująca wymiary obrazka
    struct ImageSize {
        int width;
        int height;
    };

    // Funkcja obracająca obrazek
    cv::Mat rotateImage(const cv::Mat& image, RotationDirection direction) {
        if (direction == RotationDirection::CLOCKWISE) {
            cv::transpose(image, image);
            cv::flip(image, image, 1);
        } else {
            cv::transpose(image, image);
            cv::flip(image, image, 0);
        }
        return image;
    }

    // Funkcja zmieniająca rozmiar obrazka
    cv::Mat resizeImage(const cv::Mat& image, const ImageSize& size) {
        cv::Mat resizedImage;
        cv::resize(image, resizedImage, cv::Size(size.width, size.height));
        return resizedImage;
    }

    // Funkcja zwracająca wycinek obrazka
    cv::Mat cropImage(const cv::Mat& image, const cv::Rect& roi) {
        cv::Mat croppedImage = image(roi);
        return croppedImage;
    }

} // namespace ImageProcessing

