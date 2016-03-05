class Integer {
	public:
		Integer(int x): _value(x), _count(0) {};
		int get_value() { return _value; };
		int get_count() { return _count; };
		bool operator<(const Integer& other) {
			return _value < other._value;
		}
		bool operator<=(const Integer& other) {
			return _value <= other._value;
		}
	private:
		int _value;
		int _count;
};
