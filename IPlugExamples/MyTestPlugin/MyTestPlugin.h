#ifndef __MYTESTPLUGIN__
#define __MYTESTPLUGIN__
#pragma warning( suppress : 4101 4129 )
#include "IPlug_include_in_plug_hdr.h"

class MyTestPlugin : public IPlug
{
public:
  MyTestPlugin(IPlugInstanceInfo instanceInfo);
  ~MyTestPlugin();

  void Reset();
  void OnParamChange(int paramIdx);
  void ProcessDoubleReplacing(double** inputs, double** outputs, int nFrames);

private:
  double mGain;
};

#endif
