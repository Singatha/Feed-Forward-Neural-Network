#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

double sigmoid(double value);
double sumWeights(double input1, double input2, double input3, double biasWeight, vector<double> weights);

double sigmoid(double value){
       double sig = 1/(1+exp(-(value)));
       return sig;
}

double sumWeights(double input1, double input2, double input3, double biasWeight, vector<double> weights){
       double net = (input1*weights[0]) + (input2*weights[1]) + (input3*weights[2]) + biasWeight;
       return net;
}

int main(){
    
    vector<double> x = {1.30, 2.70, 0.80};
    
    vector<double> hiddenWeight1 = {0.1, 0.2, 0.5};
    vector<double> hiddenWeight2 = {-0.4, 1.0, -0.6};
    vector<double> outputWeights = {0.8, 1.0};
    
    double biasLayer1 = 0.1;
    double biasLayer2 = -0.3;
    
    double hiddenNeuron1 = sumWeights(x[0], x[1], x[2], biasLayer1, hiddenWeight1);
    double hiddenNeuron2 = sumWeights(x[0], x[1], x[2], biasLayer2, hiddenWeight2);
    
    double hiddenOutput1 = sigmoid(hiddenNeuron1);
    double hiddenOutput2 = sigmoid(hiddenNeuron2);
    
    cout << "Hidden Layer 1 Neuron: " << hiddenOutput1 << "\n";    
    cout << "Hidden Layer 2 Neuron: " << hiddenOutput2 << "\n";
    
    double output = (hiddenOutput1*outputWeights[0])+(hiddenOutput2*outputWeights[1])-0.3;
    
    double trueOutput = sigmoid(output);
    double expectedOutput = 0.36;
    
    double error = 0.5*pow((expectedOutput-trueOutput),2);
    
    cout << "Output : " << trueOutput << "\n";
    cout << "Mean Square Error : " << error  << "\n";
    
}