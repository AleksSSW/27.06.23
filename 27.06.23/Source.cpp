#include <iostream>
#include <cmath>

class Money {
private:
	 long _rub;
	unsigned char _cop;

public:
	Money ( long rub, unsigned char cop = 0): _rub(rub), _cop(cop){}

	 long GetRub() const {
		return _rub;
	}

	unsigned char GetCop() const {
		return _cop;
	}

	long ReturnCop() const {
		return _rub * 100 + _cop;
	}


};

Money operator +(const Money& m1, const Money& m2) {
	return Money (m1.GetRub() + m2. GetRub()  + (m1.GetCop() + m2.GetCop() > 99 ? 1 :0), 
		 (m1.GetCop() + m2.GetCop()) % 100);
}

Money operator -(const Money& m1, const Money& m2) {
	
	
	long c1 = m1.ReturnCop();
	long c2 = m2.ReturnCop();
	if (c1 > c2)
		return Money((c1 - c2) / 100, (c1 - c2) % 100);
	return Money((c2 - c1) / 100, (c2 - c1) % 100);
	
}

Money operator *(const Money& m, double n) {
	long c = floor(m.ReturnCop() * n);
	return Money(c / 100, c %100);
}
Money operator / (const Money& m, double n) {
	long c = floor(m.ReturnCop() / n);
	return Money(c / 100, c % 100);
}

bool  operator < (const Money& m1, const Money& m2) {
	return (m1.ReturnCop() < m2.ReturnCop());
}


std::ostream& operator <<(std::ostream& out, const Money& m) {
	out << m.GetRub() << ',' << int (m.GetCop());
	return out;
}

int main() {

	Money m1(5, 8);
	Money m2(745,56);
	Money m3(74);
	Money m4(789, 73);

	std::cout << (m1* 54.7) << std::endl;
	std::cout << (m2 / 11) << std::endl;
	std::cout << (m2 + m4) << std::endl;
	std::cout << (m3- Money (241,8)) << std::endl;






	return 0;
}