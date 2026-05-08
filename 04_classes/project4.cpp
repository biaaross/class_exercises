#include <iostream>
#include <string>
#include <algorithm>

class media {
    protected:
    std::string fileName;
    size_t size;
    public:
    media(std::string n,size_t s) 
        : fileName(n),size(s) {};
    
    virtual void play();
};

void media::play() {
std::cout << "Base media playing: " << fileName << std::endl;
}


class audio : public media {
public:
audio(std::string n,size_t s) 
: media(n,s) {};

void play() override; 
};


void audio::play() {
    std::cout<<"The song is playing:"
             <<fileName<<std::endl;
}

class video : public media {
public:
video(std::string n,size_t s) 
: media(n,s) {};

void play() override;
};

void video::play()  {
    
    std::cout<<"The video is playing:"
             <<fileName
             <<"Resolition 1080p"<<std::endl;
}
};


int main() {
    int main() {
    media* m;

    m = new audio("song.mp3", 5000);
    m->play();   // audio::play()

    delete m;

    m = new video("movie.mp4", 200000);
    m->play();   // video::play()

    delete m;

   
return 0;
}