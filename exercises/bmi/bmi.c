#include "bmi.h"

// Convert inches to meters
float convertInchesToMeters(int nHeight) {
    return nHeight / 39.3701;
}

// Convert pounds to kg
float convertPoundsToKg(int nWeight) {
    return nWeight / 2.205;
}

// Compute for BMI
float getBMI(int nHeight, int nWeight) {
    float fHeightMeters = convertInchesToMeters(nHeight);
    float fWeightKilo = convertPoundsToKg(nWeight);
    return fWeightKilo / (fHeightMeters*fHeightMeters);
}