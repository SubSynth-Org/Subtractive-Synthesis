#ifndef __Synthesis__
#define __Synthesis__

//test line

#include "IPlug_include_in_plug_hdr.h"
//#include "Oscillator.h"
#include "MIDIReceiver.h"
//#include "EnvelopeGenerator.h"
//#include "Filter.h"
#include "VoiceManager.h"

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

    VoiceManager voiceManager;
    void CreateParams();
    void CreateGraphics();

    EnvelopeGenerator mFilterEnvelopeGenerator;

   

    void CreatePresets();
 
    MIDIReceiver mMIDIReceiver;
    IControl* mVirtualKeyboard;
    void processVirtualKeyboard();
   
  
   
};

#endif
