#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.h"
#include "Filter.h"
#include "EnvelopeGenerator.h"
#include "GallantSignal.h"
#include "Oscillator.h"



//Filter* testFilter = new Filter; 
//EnvelopeGenerator* testMultiplier = new EnvelopeGenerator;
//EnvelopeGenerator* testSample = new EnvelopeGenerator;
//EnvelopeGenerator* testStage = new EnvelopeGenerator; 
//EnvelopeGenerator*   testSampleRate = new EnvelopeGenerator; 
//Oscillator* testSetMode = new Oscillator; 
//Oscillator* testIncrement = new Oscillator; 
//Oscillator* testGenerator = new Oscillator; 
//Oscillator* testGeneratorLimits = new Oscillator; 
Oscillator* testNextSample = new Oscillator; 



/*TEST_CASE(Test for Filter) {
    REQUIRE(testFilter->process(0.0) == 0.0);
    REQUIRE(testFilter->process(0.25) > 0.0);
    REQUIRE(testFilter->process(0.50) > 0.0);
    REQUIRE(testFilter->process(0.75) > 0.0);
    REQUIRE(testFilter->process(0.99) > 0.0);
} */

/* TEST_CASE("Test for EnvelopeGen") {
    // case for inputs > 1, startLevel < endLevel --> multiplier > 1
    REQUIRE(testGen->testCalculateMultiplier(1.1, 1.2, 1000) > 1);
    // case for inputs < 1, startLevel > endLevel --> multiplier < 1
    REQUIRE(testGen->testCalculateMultiplier(1.2, 1.1, 1000) < 1);
    // case for startLevel > 1, endLevel < 1 --> multiplier < 1
    REQUIRE(testGen->testCalculateMultiplier(1.1, 0.5, 1000) < 1);
    // case for startLevel < 1, endLevel > 1 --> multiplier > 1
    REQUIRE(testGen->testCalculateMultiplier(0.5, 1.1, 1000) > 1);
    // case for startLevel = 0, endLevel > 1 --> multiplier > 1
    REQUIRE(testGen->testCalculateMultiplier(0.0, 1.1, 1000) > 1);
   // case for startLevel > 1, endLevel = 0 --> multiplier < 1
    REQUIRE(testGen->testCalculateMultiplier(1.1, 0.0, 1000) < 1);
    // case for startLevel < 1, endLevel = 0 --> multiplier < 1
    REQUIRE(testGen->testCalculateMultiplier(0.5, 0.0, 1000) < 1);
    // case for startLevel = 0, endLevel > 1 --> multiplier > 1
    REQUIRE(testGen->testCalculateMultiplier(0.0, 1.1, 1000) > 1);
    // case for startLevel = 0, endLevel < 1 --> multiplier > 1
    REQUIRE(testGen->testCalculateMultiplier(0.0, 0.5, 1000) > 1);
} */

/*TEST_CASE("Test for next sample") {
    REQUIRE(testSample->nextSample() == 0.0001);
} */

 /* TEST_CASE("Test for set stage") {


        //init values for Envelope Stages: 
        //stageValue[ENVELOPE_STAGE_OFF] = 0.0;
        //stageValue[ENVELOPE_STAGE_ATTACK] = 0.01;
        //stageValue[ENVELOPE_STAGE_DECAY] = 0.5;
        //stageValue[ENVELOPE_STAGE_SUSTAIN] = 0.1;
        //stageValue[ENVELOPE_STAGE_RELEASE] = 1.0;
    

    //REQUIRE(testStage->testSetStageValue(testStage->ENVELOPE_STAGE_ATTACK, 0.5) == 1.0); 
    //REQUIRE(testStage->testSetStageValue(testStage->ENVELOPE_STAGE_DECAY, 0.5) > 1.0);
    //REQUIRE(testStage->testSetStageValue(testStage->ENVELOPE_STAGE_RELEASE, 0.5) == 0.0001);
    //REQUIRE(testStage->testSetStageValue(testStage->ENVELOPE_STAGE_SUSTAIN, 0.5) == 0.5);

} */

/* TEST_CASE("Test sample rate") {
    REQUIRE(testSampleRate->testSetSampleRate(0.5) == 0.5);
} */

/*TEST_CASE("Test set oscillator mode") {
    // check if proper wave mode is set, return position in OscillatorMode enum 

    REQUIRE(testSetMode->testSetMode(OSCILLATOR_MODE_SINE) == 0); 
    REQUIRE(testSetMode->testSetMode(OSCILLATOR_MODE_SAW) == 1);
    REQUIRE(testSetMode->testSetMode(OSCILLATOR_MODE_SQUARE) == 2);
    REQUIRE(testSetMode->testSetMode(OSCILLATOR_MODE_TRIANGLE) == 3);
} */

/* TEST_CASE("Test update increment") {

    //  mPhaseIncrement = mFrequency * 2 * mPI / mSampleRate;

    REQUIRE(testIncrement->testUpdateIncrement() < 0.0627); 
} */

/* TEST_CASE("Test osc generator mPhase") {
    double buffer[99999];

    //NOTE: each wave-form must be test separately due to global initialization of buffer[] 

    // mPhase goes from 0 upwards, and jumps back to 0 when it reaches twoPI

   //demonstrate jumpback to 0 for sine-wave mode 
   //REQUIRE(testGenerator->testGenerate(buffer, 0.1, OSCILLATOR_MODE_SINE) == 0); // sin(0) == 0
   //REQUIRE(testGenerator->testGenerate(buffer, 999, OSCILLATOR_MODE_SINE) <= 6.079);
   //REQUIRE(testGenerator->testGenerate(buffer, 9999, OSCILLATOR_MODE_SINE) <= 4.7); // mPhase -= twoPI ensures mPhase never passes twoPI
  
   //demonstrate jumpback to 0 for saw-wave mode
   //REQUIRE(testGenerator->testGenerate(buffer, 0.1, OSCILLATOR_MODE_SAW) == 0); // sin(0) == 0
   //REQUIRE(testGenerator->testGenerate(buffer, 999, OSCILLATOR_MODE_SAW) <= 6.079);
   //REQUIRE(testGenerator->testGenerate(buffer, 9999, OSCILLATOR_MODE_SAW) <= 4.7); // mPhase -= twoPI ensures mPhase never passes twoPI

   //demonstrate jumpback to 0 for square-wave mode
   //REQUIRE(testGenerator->testGenerate(buffer, 0.1, OSCILLATOR_MODE_SAW) == 0); // sin(0) == 0
   //REQUIRE(testGenerator->testGenerate(buffer, 999, OSCILLATOR_MODE_SAW) <= 6.079);
   //REQUIRE(testGenerator->testGenerate(buffer, 9999, OSCILLATOR_MODE_SAW) <= 4.7); // mPhase -= twoPI ensures mPhase never passes twoPI

   //demonstrate jumpback to 0 for triangle-wave mode
   //REQUIRE(testGenerator->testGenerate(buffer, 0.1, OSCILLATOR_MODE_SAW) == 0); // sin(0) == 0
   //REQUIRE(testGenerator->testGenerate(buffer, 999, OSCILLATOR_MODE_SAW) <= 6.079);
   //REQUIRE(testGenerator->testGenerate(buffer, 9999, OSCILLATOR_MODE_SAW) <= 4.7); // mPhase -= twoPI ensures mPhase never passes twoPI
} */

/*TEST_CASE("Test generator limits") {
    double buffer[9999]; 

    //NOTE: each wave-form must be test separately due to global initialization of buffer[] 


    // check if all values generated for sine-wave are between [-1.0, 1.0], return 1 if there is value in buffer[] that is out of bounds
    //REQUIRE(testGeneratorLimits->testGenerateLimits(buffer, 9999, OSCILLATOR_MODE_SINE) == 0); 

    // check if all values generated for saw-wave are between [-1.0, 1.0], return 1 if there is value in buffer[] that is out of bounds
    //REQUIRE(testGeneratorLimits->testGenerateLimits(buffer, 9999, OSCILLATOR_MODE_SAW) == 0);

    // check if all values generated for square-wave are between [-1.0, 1.0], return 1 if there is value in buffer[] that is out of bounds
    //REQUIRE(testGeneratorLimits->testGenerateLimits(buffer, 9999, OSCILLATOR_MODE_SQUARE) == 0);

    // check if all values generated for triangle-wave are between [-1.0, 1.0], return 1 if there is value in buffer[] that is out of bounds
    //REQUIRE(testGeneratorLimits->testGenerateLimits(buffer, 9999, OSCILLATOR_MODE_TRIANGLE) == 0);
} */

/* TEST_CASE("Test osc next sample") {
    //case for no note played/mute, wave-form does not matter
    //REQUIRE(testNextSample->testNextSample(false, OSCILLATOR_MODE_SINE) == 0.0);

    //case for not muted and sine-wave, check if 
    //REQUIRE(testNextSample->testNextSample(false, 0.0, OSCILLATOR_MODE_SINE) == 0.0); //sin(mPhase) initially = 0.0

    //case for not muted and saw-wave
    //REQUIRE(testNextSample->testNextSample(false, 0.0, OSCILLATOR_MODE_SAW) == 1.0); 

     //case for not muted and square-wave
    //REQUIRE(testNextSample->testNextSample(false, 0.0, OSCILLATOR_MODE_SQUARE) == 1.0); 

     //case for not muted and triangle-wave
    //REQUIRE(testNextSample->testNextSample(false, 0.0, OSCILLATOR_MODE_TRIANGLE) == 1.0); 

} */