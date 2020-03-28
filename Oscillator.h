<<<<<<< Updated upstream
#include <math.h>

enum OscillatorMode {
    OSCILLATOR_MODE_SINE,
    OSCILLATOR_MODE_SAW,
    OSCILLATOR_MODE_SQUARE,
    OSCILLATOR_MODE_TRIANGLE
=======
//
//  Oscillator.h
//  Synthesis
//
//  Created by Martin on 08.04.14.
//
//

#ifndef __Synthesis__Oscillator__
#define __Synthesis__Oscillator__

#include <math.h>

enum OscillatorMode {
    OSCILLATOR_MODE_SINE = 0,
    OSCILLATOR_MODE_SAW,
    OSCILLATOR_MODE_SQUARE,
    OSCILLATOR_MODE_TRIANGLE,
    kNumOscillatorModes
>>>>>>> Stashed changes
};

class Oscillator {
private:
    OscillatorMode mOscillatorMode;
    const double mPI;
<<<<<<< Updated upstream
=======
    const double twoPI;
    bool isMuted;   
>>>>>>> Stashed changes
    double mFrequency;
    double mPhase;
    double mSampleRate;
    double mPhaseIncrement;
    void updateIncrement();
public:
    void setMode(OscillatorMode mode);
    void setFrequency(double frequency);
    void setSampleRate(double sampleRate);
    void generate(double* buffer, int nFrames);
    Oscillator() :
<<<<<<< Updated upstream
        mOscillatorMode(OSCILLATOR_MODE_SINE),
        mPI(2 * acos(0.0)),
        mFrequency(440.0),
        mPhase(0.0),
        mSampleRate(44100.0) {
        updateIncrement();
    };
};
=======
    mOscillatorMode(OSCILLATOR_MODE_SINE),
    mPI(2*acos(0.0)),
    twoPI(2 * mPI),
    isMuted(true),
    mFrequency(440.0),
    mPhase(0.0),
    mSampleRate(44100.0) { updateIncrement(); };
    inline void setMuted(bool muted) { isMuted = muted; }
    double nextSample();
};

#endif /* defined(__Synthesis__Oscillator__) */
>>>>>>> Stashed changes
