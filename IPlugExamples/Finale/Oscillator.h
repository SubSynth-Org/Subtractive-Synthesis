#pragma once

#include <math.h>

  

class Oscillator {
public:
    void reset() { mPhase = 0.0; }

    enum OscillatorMode {
        OSCILLATOR_MODE_SINE = 0,
        OSCILLATOR_MODE_SAW,
        OSCILLATOR_MODE_SQUARE,
        OSCILLATOR_MODE_TRIANGLE,
        kNumOscillatorModes
    };

    void setMode(OscillatorMode mode);
    void setFrequency(double frequency);
    void setSampleRate(double sampleRate);
    void generate(double* buffer, int nFrames);
    // inline void setMuted(bool muted) { isMuted = muted; }
    double nextSample();
    void setPitchMod(double amount);

    Oscillator() :
        mOscillatorMode(OSCILLATOR_MODE_SINE),
        mPI(2 * acos(0.0)),
        twoPI(2 * mPI),
        mFrequency(440.0),
        mPhase(0.0),
        mPitchMod(0.0)
    {};


private:
        double mPitchMod;
        OscillatorMode mOscillatorMode;
        const double mPI;
        const double twoPI = 2 * mPI;
        double mFrequency;
        double mPhase;
       static double mSampleRate;
        double mPhaseIncrement;
        void updateIncrement();
      
        };
    
