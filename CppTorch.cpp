// CppTorch.cpp : Defines the entry point for the application.
//

#include <torch/torch.h>
#include <iostream>

int main() {
	torch::Tensor tensor = torch::rand({ 2, 3, 8, 9 });
	std::cout << tensor << std::endl;
}
