#include <torch/torch.h>
#include <iostream>

int main() {
    torch::Tensor tensor = torch::rand({2, 3});
    std::cout << "Here is a random torch::Tensor:\n" << tensor << std::endl;

    // Check if CUDA is available and then create a tensor on GPU
    if (torch::cuda::is_available()) {
        std::cout << "CUDA is available! Creating a tensor on GPU." << std::endl;
        torch::Tensor gpu_tensor = torch::rand({2, 3}).to(torch::kCUDA);
        std::cout << "GPU tensor:\n" << gpu_tensor << std::endl;
    } else {
        std::cout << "CUDA is not available." << std::endl;
    }

    return 0;
}
