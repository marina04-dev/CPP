#include <iostream>
#include <string>
using namespace std;

#define SIZE 100

class Video {
  public:
    friend ostream &operator<<(ostream &left, Video &right);
    int get_duration() const;
    void set_video(string in_artist_name, string in_track_name, int in_duration);
  private:
    string track_name;
    string artist_name;
    int duration;
};

class Playlist {
  public:
    Playlist(string in_name, string in_desc);
    void add_video(Video in_video);
    friend ostream &operator<<(ostream &left, Playlist &right);
  protected:
    string name;
    string desc;
    int dur;
    Video videos[SIZE];
    int videos_size;
};

class ClassicalPlaylist: public Playlist {
  public:
    ClassicalPlaylist(string in_name, string in_desc, string in_period);
    friend ostream &operator<<(ostream &left, ClassicalPlaylist &right);
  private:
    string period;
};

int main() {
  ClassicalPlaylist l("My Playlist", "All The Hits", "Pop");
  Video temp;
  temp.set_video("Taylor Swift", "Love Song", 207);
  l.add_video(temp);
  temp.set_video("Sin Boy","Mama", 400);
  l.add_video(temp);
  cout<<l;
  return 0;
}

int Video::get_duration() const {
  return duration;
}

ostream &operator<<(ostream &left, Video &right) {
  left<<", ( "<<right.artist_name<<", "<<right.track_name<<",  "<<right.duration<<")";
  return left;
}

Playlist::Playlist(string in_name, string in_desc) {
  name = in_name;
  desc = in_desc;
  dur = 0;
  videos_size = 0;
}

void Playlist::add_video(Video in_video) {
  videos[videos_size] = in_video;
  videos_size++;
  dur += in_video.get_duration();
}

ostream &operator<<(ostream &left, Playlist &right) {
  left<<"[ "<<right.name<<", "<<right.desc<<", "<<right.dur;
  for (int i=0; i<right.videos_size; i++) {
    left<<right.videos[i];
  }
  left<<"]";
  return left;
}

void Video::set_video(string in_artist_name, string in_track_name, int in_duration) {
  artist_name = in_artist_name;
  track_name = in_track_name;
  duration = in_duration;
}

ClassicalPlaylist::ClassicalPlaylist(string in_name, string in_desc, string in_period):Playlist(in_name, in_desc) {
    period = in_period;
}

ostream &operator<<(ostream &left, ClassicalPlaylist &right) {
    left<<"["<<right.name<<" ,"<<right.desc<<" ,"<<right.period<<" ,"<<right.dur;
    for (int i=0; i<right.videos_size; i++) {
        left<<right.videos[i];
    }
    left<<"]";
    return left;
}
