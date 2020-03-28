#! /bin/sh

<<<<<<< Updated upstream
#shell script to automate IPlug Project build, code-signing and packaging on OSX

BASEDIR=$(dirname $0)
=======
BASEDIR=$(dirname $0)

# AAX codesigning requires ashelper tool in /usr/local/bin and aax.key/.crt in ./../../../Certificates/


>>>>>>> Stashed changes
cd $BASEDIR

#---------------------------------------------------------------------------------------------------------

#variables

VERSION=`echo | grep PLUG_VER resource.h`
VERSION=${VERSION//\#define PLUG_VER }
VERSION=${VERSION//\'}
MAJOR_VERSION=$(($VERSION & 0xFFFF0000))
MAJOR_VERSION=$(($MAJOR_VERSION >> 16)) 
MINOR_VERSION=$(($VERSION & 0x0000FF00))
MINOR_VERSION=$(($MINOR_VERSION >> 8)) 
BUG_FIX=$(($VERSION & 0x000000FF))

FULL_VERSION=$MAJOR_VERSION"."$MINOR_VERSION"."$BUG_FIX

<<<<<<< Updated upstream
PLUGIN_NAME=`echo | grep BUNDLE_NAME resource.h`
PLUGIN_NAME=${PLUGIN_NAME//\#define BUNDLE_NAME }
PLUGIN_NAME=${PLUGIN_NAME//\"}

# work out the paths to the binaries

VST2=`echo | grep VST_FOLDER ../../common.xcconfig`
VST2=${VST2//\VST_FOLDER = }/$PLUGIN_NAME.vst

VST3=`echo | grep VST3_FOLDER ../../common.xcconfig`
VST3=${VST3//\VST3_FOLDER = }/$PLUGIN_NAME.vst3

AU=`echo | grep AU_FOLDER ../../common.xcconfig`
AU=${AU//\AU_FOLDER = }/$PLUGIN_NAME.component

APP=`echo | grep APP_FOLDER ../../common.xcconfig`
APP=${APP//\APP_FOLDER = }/$PLUGIN_NAME.app

# Dev build folder
RTAS=`echo | grep RTAS_FOLDER ../../common.xcconfig`
RTAS=${RTAS//\RTAS_FOLDER = }/$PLUGIN_NAME.dpm
RTAS_FINAL="/Library/Application Support/Digidesign/Plug-Ins/$PLUGIN_NAME.dpm"

# Dev build folder
AAX=`echo | grep AAX_FOLDER ../../common.xcconfig`
AAX=${AAX//\AAX_FOLDER = }/$PLUGIN_NAME.aaxplugin
AAX_FINAL="/Library/Application Support/Avid/Audio/Plug-Ins/$PLUGIN_NAME.aaxplugin"

PKG="installer/build-mac/$PLUGIN_NAME Installer.pkg"
PKG_US="installer/build-mac/$PLUGIN_NAME Installer.unsigned.pkg"
=======
# work out the paths to the bundles

VST2=`echo | grep VST_FOLDER ../../common.xcconfig`
VST2=${VST2//\VST_FOLDER = }/Synthesis.vst

VST3=`echo | grep VST3_FOLDER ../../common.xcconfig`
VST3=${VST3//\VST3_FOLDER = }/Synthesis.vst3

AU=`echo | grep AU_FOLDER ../../common.xcconfig`
AU=${AU//\AU_FOLDER = }/Synthesis.component

APP=`echo | grep APP_FOLDER ../../common.xcconfig`
APP=${APP//\APP_FOLDER = }/Synthesis.app

# Dev build folder
RTAS=`echo | grep RTAS_FOLDER ../../common.xcconfig`
RTAS=${RTAS//\RTAS_FOLDER = }/Synthesis.dpm
RTAS_FINAL="/Library/Application Support/Digidesign/Plug-Ins/Synthesis.dpm"

# Dev build folder
AAX=`echo | grep AAX_FOLDER ../../common.xcconfig`
AAX=${AAX//\AAX_FOLDER = }/Synthesis.aaxplugin
AAX_FINAL="/Library/Application Support/Avid/Audio/Plug-Ins/Synthesis.aaxplugin"

PKG='installer/build-mac/Synthesis Installer.pkg'
PKG_US='installer/build-mac/Synthesis Installer.unsigned.pkg'
>>>>>>> Stashed changes

CERT_ID=`echo | grep CERTIFICATE_ID ../../common.xcconfig`
CERT_ID=${CERT_ID//\CERTIFICATE_ID = }

<<<<<<< Updated upstream
echo "making $PLUGIN_NAME version $FULL_VERSION mac distribution..."
=======
echo "making Synthesis version $FULL_VERSION mac distribution..."
>>>>>>> Stashed changes
echo ""

#---------------------------------------------------------------------------------------------------------

<<<<<<< Updated upstream
#call python script to update version numbers
./update_version.py

#here you can use the touch command to force xcode to rebuild
#touch MyPlugin.h

#---------------------------------------------------------------------------------------------------------

#if you are zipping the binaries, remove existing dist folder
=======
./update_version.py

#could use touch to force a rebuild
#touch blah.h

#---------------------------------------------------------------------------------------------------------

#remove existing dist folder
>>>>>>> Stashed changes
#if [ -d installer/dist ] 
#then
#  rm -R installer/dist
#fi

#mkdir installer/dist

#remove existing binaries
if [ -d $APP ] 
then
  sudo rm -f -R -f $APP
fi

if [ -d $AU ] 
then
  sudo rm -f -R $AU
fi

if [ -d $VST2 ] 
then
  sudo rm -f -R $VST2
fi

if [ -d $VST3 ] 
then
  sudo rm -f -R $VST3
fi

if [ -d "${RTAS}" ] 
then
  sudo rm -f -R "${RTAS}"
fi

if [ -d "${RTAS_FINAL}" ] 
then
  sudo rm -f -R "${RTAS_FINAL}"
fi

if [ -d "${AAX}" ] 
then
  sudo rm -f -R "${AAX}"
fi

if [ -d "${AAX_FINAL}" ] 
then
  sudo rm -f -R "${AAX_FINAL}"
fi

#---------------------------------------------------------------------------------------------------------

# build xcode project. Change target to build individual formats 
<<<<<<< Updated upstream
xcodebuild -project $PLUGIN_NAME.xcodeproj -xcconfig $PLUGIN_NAME.xcconfig -target "All" -configuration Release 2> ./build-mac.log
=======
xcodebuild -project Synthesis.xcodeproj -xcconfig Synthesis.xcconfig -target "All" -configuration Release 2> ./build-mac.log
#xcodebuild -project Synthesis-ios.xcodeproj -xcconfig Synthesis.xcconfig -target "IOSAPP" -configuration Release
>>>>>>> Stashed changes

if [ -s build-mac.log ]
then
  echo "build failed due to following errors:"
  echo ""
  cat build-mac.log
  exit 1
else
 rm build-mac.log
fi

#---------------------------------------------------------------------------------------------------------

#icon stuff - http://maxao.free.fr/telechargements/setfileicon.gz
echo "setting icons"
echo ""
<<<<<<< Updated upstream
setfileicon resources/$PLUGIN_NAME.icns $AU
setfileicon resources/$PLUGIN_NAME.icns $VST2
setfileicon resources/$PLUGIN_NAME.icns $VST3
setfileicon resources/$PLUGIN_NAME.icns "${RTAS}"
setfileicon resources/$PLUGIN_NAME.icns "${AAX}"

#---------------------------------------------------------------------------------------------------------

#strip debug symbols from binaries

echo "striping binaries"
strip -x $AU/Contents/MacOS/$PLUGIN_NAME
strip -x $VST2/Contents/MacOS/$PLUGIN_NAME
strip -x $VST3/Contents/MacOS/$PLUGIN_NAME
strip -x $APP/Contents/MacOS/$PLUGIN_NAME
strip -x "${AAX}/Contents/MacOS/$PLUGIN_NAME"
strip -x "${RTAS}/Contents/MacOS/$PLUGIN_NAME"
=======
setfileicon resources/Synthesis.icns $AU
setfileicon resources/Synthesis.icns $VST2
setfileicon resources/Synthesis.icns $VST3
setfileicon resources/Synthesis.icns "${RTAS}"
setfileicon resources/Synthesis.icns "${AAX}"
>>>>>>> Stashed changes

#---------------------------------------------------------------------------------------------------------

#ProTools stuff

<<<<<<< Updated upstream
echo "copying RTAS PLUGIN_NAME from 3PDev to main RTAS folder"
sudo cp -p -R "${RTAS}" "${RTAS_FINAL}"

echo "copying AAX PLUGIN_NAME from 3PDev to main AAX folder"
sudo cp -p -R "${AAX}" "${AAX_FINAL}"

echo "code sign AAX binary"
#... consult PACE documentation

#---------------------------------------------------------------------------------------------------------

#Mac AppStore stuff

#xcodebuild -project $PLUGIN_NAME.xcodeproj -xcconfig $PLUGIN_NAME.xcconfig -target "APP" -configuration Release 2> ./build-mac.log

#echo "code signing app for appstore"
#echo ""
#codesign -f -s "3rd Party Mac Developer Application: ""${CERT_ID}" $APP --entitlements resources/$PLUGIN_NAME.entitlements
 
#echo "building pkg for app store"
#echo ""
#productbuild \
#     --component $APP /Applications \
#     --sign "3rd Party Mac Developer Installer: ""${CERT_ID}" \
#     --product "/Applications/$PLUGIN_NAME.app/Contents/Info.plist" installer/$PLUGIN_NAME.pkg
=======
echo "copying RTAS bundle from 3PDev to main RTAS folder"
sudo cp -p -R "${RTAS}" "${RTAS_FINAL}"

echo "copying AAX bundle from 3PDev to main AAX folder"
sudo cp -p -R "${AAX}" "${AAX_FINAL}"

echo "code sign AAX binary"
sudo ashelper -f "${AAX_FINAL}/Contents/MacOS/Synthesis" -l ../../../Certificates/aax.crt -k ../../../Certificates/aax.key -o "${AAX_FINAL}/Contents/MacOS/Synthesis"
#---------------------------------------------------------------------------------------------------------

#appstore stuff

# echo "code signing app for appstore"
# echo ""
# codesign -f -s "3rd Party Mac Developer Application: ""${CERT_ID}" $APP --entitlements resources/Synthesis.entitlements
#  
# echo "building pkg for app store"
# productbuild \
#      --component $APP /Applications \
#      --sign "3rd Party Mac Developer Installer: ""${CERT_ID}" \
#      --product "/Applications/Synthesis.app/Contents/Info.plist" installer/Synthesis.pkg
>>>>>>> Stashed changes

#---------------------------------------------------------------------------------------------------------

#10.8 Gatekeeper/Developer ID stuff

<<<<<<< Updated upstream
echo "code app binary for Gatekeeper on 10.8"
echo ""
codesign -f -s "Developer ID Application: ""${CERT_ID}" $APP

#TODO: code-sign plug-in binaries too?
=======
#echo "code sign app for Gatekeeper on 10.8"
#echo ""
#codesign -f -s "Developer ID Application: ""${CERT_ID}" $APP
>>>>>>> Stashed changes

#---------------------------------------------------------------------------------------------------------

# installer, uses Packages http://s.sudre.free.fr/Software/Packages/about.html
<<<<<<< Updated upstream
sudo sudo rm -R -f installer/$PLUGIN_NAME-mac.dmg

echo "building installer"
echo ""
packagesbuild installer/$PLUGIN_NAME.pkgproj

echo "code-sign installer for Gatekeeper on 10.8"
echo ""
mv "${PKG}" "${PKG_US}"
productsign --sign "Developer ID Installer: ""${CERT_ID}" "${PKG_US}" "${PKG}"
                   
rm -R -f "${PKG_US}"

#set installer icon
setfileicon resources/$PLUGIN_NAME.icns "${PKG}"
=======
sudo sudo rm -R -f installer/Synthesis-mac.dmg

echo "building installer"
echo ""
packagesbuild installer/Synthesis.pkgproj

#echo "code sign installer for Gatekeeper on 10.8"
#echo ""
#mv "${PKG}" "${PKG_US}"
#productsign --sign "Developer ID Installer: ""${CERT_ID}" "${PKG_US}" "${PKG}"
                   
#rm -R -f "${PKG_US}"

#set installer icon
setfileicon resources/Synthesis.icns "${PKG}"
>>>>>>> Stashed changes

#---------------------------------------------------------------------------------------------------------

# dmg, can use dmgcanvas http://www.araelium.com/dmgcanvas/ to make a nice dmg

echo "building dmg"
echo ""

<<<<<<< Updated upstream
if [ -d installer/$PLUGIN_NAME.dmgCanvas ]
then
  dmgcanvas installer/$PLUGIN_NAME.dmgCanvas installer/$PLUGIN_NAME-mac.dmg
else
  hdiutil create installer/$PLUGIN_NAME.dmg -srcfolder installer/build-mac/ -ov -anyowners -volname $PLUGIN_NAME
  
  if [ -f installer/$PLUGIN_NAME-mac.dmg ]
  then
   rm -f installer/$PLUGIN_NAME-mac.dmg
  fi
  
  hdiutil convert installer/$PLUGIN_NAME.dmg -format UDZO -o installer/$PLUGIN_NAME-mac.dmg
  sudo rm -R -f installer/$PLUGIN_NAME.dmg
=======
if [ -d installer/Synthesis.dmgCanvas ]
then
  dmgcanvas installer/Synthesis.dmgCanvas installer/Synthesis-mac.dmg
else
  hdiutil create installer/Synthesis.dmg -srcfolder installer/build-mac/ -ov -anyowners -volname Synthesis
  
  if [ -f installer/Synthesis-mac.dmg ]
  then
   rm -f installer/Synthesis-mac.dmg
  fi
  
  hdiutil convert installer/Synthesis.dmg -format UDZO -o installer/Synthesis-mac.dmg
  sudo rm -R -f installer/Synthesis.dmg
>>>>>>> Stashed changes
fi

sudo rm -R -f installer/build-mac/

#---------------------------------------------------------------------------------------------------------
# zip

# echo "copying binaries..."
# echo ""
<<<<<<< Updated upstream
# cp -R $AU installer/dist/$PLUGIN_NAME.component
# cp -R $VST2 installer/dist/$PLUGIN_NAME.vst
# cp -R $VST3 installer/dist/$PLUGIN_NAME.vst3
# cp -R $RTAS installer/dist/$PLUGIN_NAME.dpm
# cp -R $AAX installer/dist/$PLUGIN_NAME.aaxplugin
# cp -R $APP installer/dist/$PLUGIN_NAME.app
# 
# echo "zipping binaries..."
# echo ""
# ditto -c -k installer/dist installer/$PLUGIN_NAME-mac.zip
=======
# cp -R $AU installer/dist/Synthesis.component
# cp -R $VST2 installer/dist/Synthesis.vst
# cp -R $VST3 installer/dist/Synthesis.vst3
# cp -R $RTAS installer/dist/Synthesis.dpm
# cp -R $AAX installer/dist/Synthesis.aaxplugin
# cp -R $APP installer/dist/Synthesis.app
# 
# echo "zipping binaries..."
# echo ""
# ditto -c -k installer/dist installer/Synthesis-mac.zip
>>>>>>> Stashed changes
# rm -R installer/dist

#---------------------------------------------------------------------------------------------------------

echo "done"