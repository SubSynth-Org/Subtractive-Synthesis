#ifndef __MYSECONDPLUGIN__
#define __MYSECONDPLUGIN__

#include "IPlug_include_in_plug_hdr.h"

class MySecondPlugin : public IPlug
{
public:
  MySecondPlugin(IPlugInstanceInfo instanceInfo);
  ~MySecondPlugin();

  void Reset();
  void OnParamChange(int paramIdx);
  void ProcessDoubleReplacing(double** inputs, double** outputs, int nFrames);

private:
  double mGain;
};

#endif
