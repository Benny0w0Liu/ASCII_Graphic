#include "Matrix.h"
//row_operation
const std::vector< std::vector <double>> swapping(std::vector< std::vector <double>> m, int a, int b) {
	std::vector <double> temp = m.at(a);
	m.at(a) = m.at(b);
	m.at(b) = temp;
	return m;
}
const std::vector< std::vector <double>> resca1ing(std::vector< std::vector <double>> m, int a, double k) {
	for (int i = 0; i < m.at(a).size(); i++) {
		m.at(a).at(i) *= k;
	}
	return m;
}
const std::vector< std::vector <double>> row_combination(std::vector< std::vector <double>> m, int a, int b, double k) {
	for (int i = 0; i < m.at(a).size(); i++) {
		m.at(a).at(i) += m.at(b).at(i)*k;
	}
	return m;
}

const std::vector< std::vector <double>> identity(int n) {
	std::vector< std::vector <double>> I(n, std::vector<double>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				I[i][j] = 1;
			}
		}
	}
	return I;
}


const std::vector< std::vector <double>> operator *(const std::vector< std::vector <double>> a, const std::vector< std::vector <double>> b) {
	std::vector< std::vector <double>> result(a.size(), std::vector<double>(b[0].size(), 0));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			for (int k = 0; k < a[0].size(); k++) {
				result[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return result;
}
const std::vector< std::vector <double>> transpose(const std::vector< std::vector <double>> a) {
	std::vector< std::vector <double>> result(a[0].size(), std::vector<double>(a.size()));
	for (int i = 0; i < a[0].size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			result[i][j] = a[j][i];
		}
	}
	return result;
}
const double determinant(const std::vector< std::vector <double>> a) {
	if (a.size() == 2) {
		return a[0][0] * a[1][1] - a[0][1] * a[1][0];
	}
	std::vector< std::vector <double>> temp=a;
	double result = 0;
	for (int i = 0; i < a.size(); i++) {
		temp.erase(temp.begin() + 0);
		for (int j = 0; j < temp.size(); j++) {
			temp[j].erase(temp[j].begin() + i);
		}
		if (i % 2 == 0) { result += a[0][i] * determinant(temp); }
		else { result -= a[0][i] * determinant(temp); }

		temp = a;
	}
	return result;
}
const std::vector< std::vector <double>> inverse(std::vector< std::vector <double>> a) {
	std::vector< std::vector <double>> I = identity(a.size()), result = identity(a.size());
	if (determinant(a) == 0) {
		std::cout << "Not inversible!!!\n";
		return I;
	}
	for (int i = 0; i < a.size(); i++) {
		if (a[i][i] == 0) {
			for (int j = i+1; j < a.size(); j++) {
				if (a[j][i] != 0) {
					swapping(a, i, j);
					break;
				}
			}
		}
		result = resca1ing(result, i, 1 / a[i][i]);
		a = resca1ing(a, i, 1 / a[i][i]);
		for (int j = i+1; j < a.size() ; j++) {
			if (a[j][i] != 0) {
				result = row_combination(result, j, i, -a[j][i] / a[i][i]);
				a=row_combination(a, j, i, -a[j][i] / a[i][i]);
			}
		}
	}

	for (int i = a.size() - 1; i >= 0; i--) {
		for (int j = 0; j<i; j++) {
			if (a[j][i] != 0) {
				result = row_combination(result, j, i, -a[j][i] / a[i][i]);
				a = row_combination(a, j, i, -a[j][i] / a[i][i]);
			}
		}
	}
	return result;
}
