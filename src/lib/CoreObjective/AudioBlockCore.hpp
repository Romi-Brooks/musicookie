//
// Created by romi on 3/30/24.
//

#ifndef MUSICOOKIE_AUDIOBLOCKCORE_HPP
#define MUSICOOKIE_AUDIOBLOCKCORE_HPP
#include <vector>
#include <string>

enum AudioBlockType {
    AudioBlockType_Midi,
    AudioBlockType_Audio,
};

class AudioBlockCore {
public:
    //Audio Block Basic Functions
    //Constructor
    explicit AudioBlockCore(AudioBlockType type);
    //Destructor:
    virtual ~AudioBlockCore();

    //Get Name
    std::string GetName();
    //Give Name
    void SetName(std::string UserBlockName);
    //Get Vol
    int GetVol();
    //Set Vol
    void SetVol(int UserVol);
    //Get Pan
    int GetPan();
    //Set Pan
    void SetPan(int UserPan);
    //Get Type
    AudioBlockType GetType();
    std::string GetTypeName(); // Trans the Type enum index num to string, what a fucking tip.

private:
    //Audio Block Basic Settings
    //Name
    std::string AudioBlockName;
    //Vol
    int AudioBlockVol = 80;
    //Pan
    int AudioBlockPan = 0;
    //Type
    std::basic_string<char> BlockType;
    //Collector
    std::vector<AudioBlockCore> _blocks;
};














//This class is a subclass of AudioBlockCore, and is used to store MIDI data for synthesis
class AudioBlockMidi : public AudioBlockCore {
    explicit AudioBlockMidi(std::vector<std::string> midiData);
    std::vector<std::string> midiData;

private:
    std::vector<std::string> _midiData;

};

//This class is a subclass of AudioBlockCore, and is used to store audio data for sample playback
class AudioBlockAudio : public AudioBlockCore {
public:
    explicit AudioBlockAudio(std::vector<float> audioData);
    std::vector<float> audioData;
private:
    std::vector<float> _audioData;

};

#endif //MUSICOOKIE_AUDIOBLOCKCORE_HPP
