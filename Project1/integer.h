#ifndef INTEGER_H
#define INTEGER_H

class Integer {
	public:
		Integer(): _value(0), _count(0) {};
		Integer(int x): _value(x), _count(0) {};
		int get_value() { return _value; };
		int get_count() { return _count; };
		bool operator<(const Integer& other) {
			_count++;
			return _value < other._value;
		}
		bool operator<=(const Integer& other) {
			_count ++;
			return _value <= other._value;
		}
	private:
		int _value;
		int _count;
};

#endif
