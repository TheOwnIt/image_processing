#include <opencv2/opencv.hpp>

namespace ImageProcessing {

    // Typ wyliczeniowy reprezentuj¹cy kierunek obrotu
    enum class RotationDirection {
        CLOCKWISE,
        COUNTERCLOCKWISE
    };

    // Struktura reprezentuj¹ca wymiary obrazka
    struct ImageSize {
        int width;
        int height;
    };

    // Funkcja obracaj¹ca obrazek
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

    // Funkcja zmieniaj¹ca rozmiar obrazka
    cv::Mat resizeImage(const cv::Mat& image, const ImageSize& size) {
        cv::Mat resizedImage;
        cv::resize(image, resizedImage, cv::Size(size.width, size.height));
        return resizedImage;
    }

    // Funkcja zwracaj¹ca wycinek obrazka
    cv::Mat cropImage(const cv::Mat& image, const cv::Rect& roi) {
        cv::Mat croppedImage = image(roi);
        return croppedImage;
    }

} // namespace ImageProcessing

