class Font {
private:
	//unique object key
	string key;

	//object state
	//...
public:
	Font(const string & key) {


	}
};

class FontFactory {
private:
	map<string, Font*> fontPool;
public:
	Font * getFont(const string & key) {
		map<string, Font*>::iterator item = fontPool.find(key);
		if (item != fontPool.end()) {
			return fontPool[key];
		}
		else {
			Font * font = new Font(key);
			fontPool[key] = font;
			return font;
		}
	}
};