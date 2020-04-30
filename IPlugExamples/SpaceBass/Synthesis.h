#ifndef __Synthesis__
#define __Synthesis__

//test line

#include "IPlug_include_in_plug_hdr.h"
#include "Oscillator.h"
#include "MIDIReceiver.h"
#include "EnvelopeGenerator.h"
#include "Filter.h"

class Synthesis : public IPlug
{
public:
  Synthesis(IPlugInstanceInfo instanceInfo);
  ~Synthesis();


  // Needed for the GUI keyboard:
  // Should return non-zero if one or more keys are playing.
  inline int GetNumKeys() const { return mMIDIReceiver.getNumKeys(); };
  // Should return true if the specified key is playing.
  inline bool GetKeyStatus(int key) const { return mMIDIReceiver.getKeyStatus(key); };
  static const int virtualKeyboardMinimumNoteNumber = 48;
  int lastVirtualKeyboardNoteNumber;
 
  void ProcessMidiMsg(IMidiMsg* pMsg);   // to receive MIDI messages:
  void Reset();
  void OnParamChange(int paramIdx);
  void ProcessDoubleReplacing(double** inputs, double** outputs, int nFrames);

private:
    Oscillator mLFO;
    double lfoFilterModAmount;
    EnvelopeGenerator mFilterEnvelopeGenerator;
    double filterEnvelopeAmount;
    Filter mFilter;
    inline void onBeganEnvelopeCycle() { mOscillator.setMuted(false); }
    inline void onFinishedEnvelopeCycle() { mOscillator.setMuted(true); }
    double mFrequency;
    void CreatePresets();
    Oscillator mOscillator;
    MIDIReceiver mMIDIReceiver;
    IControl* mVirtualKeyboard;
    void processVirtualKeyboard();
    EnvelopeGenerator mEnvelopeGenerator;
    inline void onNoteOn(const int noteNumber, const int velocity) {
        mEnvelopeGenerator.enterStage(EnvelopeGenerator::ENVELOPE_STAGE_ATTACK);
        mFilterEnvelopeGenerator.enterStage(EnvelopeGenerator::ENVELOPE_STAGE_ATTACK);
    };
    inline void onNoteOff(const int noteNumber, const int velocity) {
        mEnvelopeGenerator.enterStage(EnvelopeGenerator::ENVELOPE_STAGE_RELEASE);
        mFilterEnvelopeGenerator.enterStage(EnvelopeGenerator::ENVELOPE_STAGE_RELEASE);
    };
};

#endif
