class Solution {
public:
    vector<double> convertTemperature(double celsius) 
    {
        double k = celsius + 273.1500;
        double f = celsius * 1.8000 +32.000; 
        return vector<double>{k,f};
    }
};