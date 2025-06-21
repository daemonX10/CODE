// Constructor implementation
Interest::Interest(int principal, int years, int rate)
    : principal_(principal), year_(years), rate_(rate), amount_(0.0)
{
}

// Calculate simple interest
void Interest::calculate()
{
    std::cout << "Principal: " << principal_ << std::endl;
    std::cout << "Rate: " << rate_ << "%" << std::endl;
    std::cout << "Years: " << year_ << std::endl;
    
    amount_ = static_cast<double>(principal_ * year_ * rate_) / 100.0;
    
    std::cout << "Simple Interest: " << std::fixed << std::setprecision(2) 
              << amount_ << std::endl;
    std::cout << "Total Amount: " << std::fixed << std::setprecision(2) 
              << (principal_ + amount_) << std::endl;
    std::cout << "------------------------" << std::endl;
}