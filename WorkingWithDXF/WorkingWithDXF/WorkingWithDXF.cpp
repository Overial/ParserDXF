// Àôàíàñüåâ Âàäèì
// ÈÄÁ-19-07

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

#include <tchar.h>
 
class Entity {
public:
	Entity() {

	}

	virtual void print() = 0;

	// virtual void reset() = 0;

	virtual ~Entity() {

	}
};

class Circle : public Entity {
private:
	float m_x,
		  m_y,
		  m_z,
		  m_radius;

public:
	Circle() {
		m_x      = 0;
		m_y      = 0;
		m_z      = 0;
		m_radius = 0;
	}

	Circle(float x, float y, float z, float radius) {
		m_x      = x;
		m_y      = y;
		m_z      = z;
		m_radius = radius;
	}

	void print() override {
		cout << "CIRCLE  "             << '\n';
		cout << "X:      " << m_x      << '\n';
		cout << "Y:      " << m_y      << '\n';
		cout << "Z:      " << m_z      << '\n';
		cout << "Radius: " << m_radius << '\n';
		cout                           << '\n';
	}

	/*
	void reset() override {
		m_x = 0;
		m_y = 0;
		m_z = 0;
	}
	*/

	~Circle() override {

	}
};

class Vertex {
private:
	float m_x,
		  m_y,
		  m_z;

public:
	Vertex() {

	}

	Vertex(float x, float y, float z) {
		m_x = x;
		m_y = y;
		m_z = z;
	}
		
	void print() {
		cout << "Vertex"     << '\n';
		cout << "X: " << m_x << '\n';
		cout << "Y: " << m_y << '\n';
		cout << "Z: " << m_z << '\n';
		cout                 << '\n';
	}

	~Vertex() {

	}
};

class Polyline : public Entity {
protected:
	vector<Vertex*> m_vVertexes;

public:
	Polyline() {

	}

	void print() {
		for (size_t i = 0; i < m_vVertexes.size(); i++) {
			
		}
	}

	~Polyline() override {

	}
};

class Ellipse : public Entity {
private:
	float m_x,
		  m_y,
		  m_z,
		  m_MajorAxisX,
		  m_MajorAxisY,
		  m_MajorAxisZ,
		  m_AxisRatio;

public:
	Ellipse() {
		m_x          = 0;
		m_y          = 0;
		m_z          = 0;
		m_MajorAxisX = 0;
		m_MajorAxisY = 0;
		m_MajorAxisZ = 0;
		m_AxisRatio  = 0;
	}

	Ellipse(float x, float y, float z, float MajorAxisX, float MajorAxisY, float MajorAxisZ, float AxisRatio) {
		m_x          = x;
		m_y          = y;
		m_z          = z;
		m_MajorAxisX = MajorAxisX;
		m_MajorAxisY = MajorAxisY;
		m_MajorAxisZ = MajorAxisZ;
		m_AxisRatio  = AxisRatio;
	}

	void print() override {
		cout << "ELLIPSE     "                 << '\n';
		cout << "X:          " << m_x          << '\n';
		cout << "Y:          " << m_y          << '\n';
		cout << "Z:          " << m_z          << '\n';
		cout << "MajorAxisX: " << m_MajorAxisX << '\n';
		cout << "MajorAxisY: " << m_MajorAxisY << '\n';
		cout << "MajorAxisZ: " << m_MajorAxisZ << '\n';
		cout << "AxisRatio:  " << m_AxisRatio  << '\n';
		cout                                   << '\n';
	}

	/*
	void reset() override {
		m_x = 0;
		m_y = 0;
		m_z = 0;
	}
	*/

	~Ellipse() override {

	}
};

class Point : public Entity {
private:
	float m_x,
		  m_y,
		  m_z;

public:
	Point() {
		m_x = 0;
		m_y = 0;
		m_z = 0;
	}

	Point(float x, float y, float z) {
		m_x = x;
		m_y = y;
		m_z = z;
	}

	void print() override {
		cout << "POINT"        << '\n';
		cout << "X:   " << m_x << '\n';
		cout << "Y:   " << m_y << '\n';
		cout << "Z:   " << m_z << '\n';
		cout                   << '\n';
	}

	/*
	void reset() override {
		m_x = 0;
		m_y = 0;
		m_z = 0;
	}
	*/

	~Point() override {

	}
};

// Î÷èñòêà ÁÄ
void del_vector(vector<Entity*>& vDatabase) {
	for (size_t i = 0; i < vDatabase.size(); i++) {
		delete vDatabase[i];
	}
}

int _tmain(int argc, _TCHAR* argv[]) {
	ifstream iFile("model.dxf");

	string strTempRead = "";

	// ÁÄ
	vector<Entity*> vDatabase;
	// Ïåðâîíà÷àëüíàÿ èíôîðìàöèÿ èç ôàéëà
	vector<string> vFileInformation;

	// ×òåíèå (ïîñòðî÷íîå)
	if (!iFile.is_open()) {
		cerr << "Failed to open model.dxf";
		
		// Êîä 1 – íå îòêðûëñÿ model.dxf
		exit(1);
	}
	else {
		while (!iFile.eof()) {
			strTempRead = "";

			getline(iFile, strTempRead);
			vFileInformation.push_back(strTempRead);

			// Óáðàòü êîììåíòàðèé äëÿ âûâîäà èíôîðìàöèè èç ôàéëà íà êîíñîëü
			cout << strTempRead << endl;
		}
	}

	iFile.close();

	// Äëÿ ïîäñ÷åòà êîëè÷åñòâà ôèãóð
	int iAmountOfFigures = 0;

	// Äëÿ ïîäñ÷åòà êîëè÷åñòâà ôèãóð ïî òèïàì
	int iAmountOfCircles   = 0,
		iAmountOfPolylines = 0,
		iAmountOfEllipses  = 0,
		iAmountOfPoints    = 0;

	// Ïðèíàäëåæíîñòü ïîëèëèíèè
	int type = 0;

	// Çàïîëíåíèå ÁÄ
	for (size_t i = 0; i < vFileInformation.size(); i++) {
		// CIRCLE
		if (vFileInformation[i] == "AcDbCircle") {
			iAmountOfFigures++;
			iAmountOfCircles++;

			float x = 0,
				  y = 0,
				  z = 0,
				  radius = 0;

			for (size_t j = i + 1; vFileInformation[j] != "  0"; j++) {
				if (vFileInformation[j] == " 10") {
					x = stof(vFileInformation[j + 1]);
				}
				else if (vFileInformation[j] == " 20") {
					y = stof(vFileInformation[j + 1]);
				}
				else if (vFileInformation[j] == " 30") {
					z = stof(vFileInformation[j + 1]);
				}
				else if (vFileInformation[j] == " 40") {
					radius = stof(vFileInformation[j + 1]);
				}
			}

			vDatabase.push_back(new Circle(x, y, z, radius));
		}

		// POLYLINE
		if (vFileInformation[i] == "POLYLINE") {
			iAmountOfFigures++;
			iAmountOfPolylines++;

			type++;
		}

		if (vFileInformation[i] == "VERTEX") {
			float x = 0,
				  y = 0,
				  z = 0;

			for (size_t j = i + 1; vFileInformation[j] != "  0"; j++) {
				if (vFileInformation[j] == " 10") {
					x = stof(vFileInformation[j + 1]);
				}
				else if (vFileInformation[j] == " 20") {
					y = stof(vFileInformation[j + 1]);
				}
				else if (vFileInformation[j] == " 30") {
					z = stof(vFileInformation[j + 1]);
				}
			}

			// vDatabase.push_back(new Vertex(type, x, y, z));
		}

		// ELLIPSE
		if (vFileInformation[i] == "AcDbEllipse") {
			iAmountOfFigures++;
			iAmountOfEllipses++;

			float x          = 0,
				  y          = 0,
				  z          = 0,
				  MajorAxisX = 0,
				  MajorAxisY = 0,
				  MajorAxisZ = 0,
				  AxisRatio  = 0;

			for (size_t j = i + 1; vFileInformation[j] != "  0"; j++) {
				if (vFileInformation[j] == " 10") {
					x = stof(vFileInformation[j + 1]);
				}
				else if (vFileInformation[j] == " 20") {
					y = stof(vFileInformation[j + 1]);
				}
				else if (vFileInformation[j] == " 30") {
					z = stof(vFileInformation[j + 1]);
				}
				else if (vFileInformation[j] == " 11") {
					MajorAxisX = stof(vFileInformation[j + 1]);
				}
				else if (vFileInformation[j] == " 21") {
					MajorAxisY = stof(vFileInformation[j + 1]);
				}
				else if (vFileInformation[j] == " 31") {
					MajorAxisZ = stof(vFileInformation[j + 1]);
				}
				else if (vFileInformation[j] == " 40") {
					AxisRatio = stof(vFileInformation[j + 1]);
				}
			}

			vDatabase.push_back(new Ellipse(x, y, z, MajorAxisX, MajorAxisY, MajorAxisZ, AxisRatio));
		}

		// POINT
		if (vFileInformation[i] == "AcDbPoint") {
			iAmountOfFigures++;
			iAmountOfPoints++;

			float x = 0,
				  y = 0,
				  z = 0;

			for (size_t j = i + 1; vFileInformation[j] != "  0"; j++) {
				if (vFileInformation[j] == " 10") {
					x = stof(vFileInformation[j + 1]);
				}
				else if (vFileInformation[j] == " 20") {
					y = stof(vFileInformation[j + 1]);
				}
				else if (vFileInformation[j] == " 30") {
					z = stof(vFileInformation[j + 1]);
				}
			}

			vDatabase.push_back(new Point(x, y, z));
		}
	}

	/*
	// Ñáðîñ êîîðäèíàò
	for (size_t i = 0; i < vDatabase.size(); i++) {
		vDatabase[i]->reset();
	}
	*/

	// Çàïèñü íîâîãî ôàéëà
	for (size_t i = 0; i < vFileInformation.size(); i++) {
		// CIRCLE
		if (vFileInformation[i] == "AcDbCircle") {
			for (size_t j = i + 1; vFileInformation[j] != "  0"; j++) {
				if (vFileInformation[j] == " 10") {
					vFileInformation[j + 1] = "0.0";
				}
				else if (vFileInformation[j] == " 20") {
					vFileInformation[j + 1] = "0.0";
				}
				else if (vFileInformation[j] == " 30") {
					vFileInformation[j + 1] = "0.0";
				}
			}
		}

		// POLYLINE
		if (vFileInformation[i] == "VERTEX") {
			for (size_t j = i + 1; vFileInformation[j] != "  0"; j++) {
				if (vFileInformation[j] == " 10") {
					float temp = stof(vFileInformation[j + 1]);
					temp -= 17.0f;
					vFileInformation[j + 1] = to_string(temp);
				}
				else if (vFileInformation[j] == " 20") {
					float temp = stof(vFileInformation[j + 1]);
					temp -= 7.0f;
					vFileInformation[j + 1] = to_string(temp);
				}
			}
		}

		// ELLIPSE
		if (vFileInformation[i] == "AcDbEllipse") {
			for (size_t j = i + 1; vFileInformation[j] != "  0"; j++) {
				if (vFileInformation[j] == " 10") {
					vFileInformation[j + 1] = "0.0";
				}
				else if (vFileInformation[j] == " 20") {
					vFileInformation[j + 1] = "0.0";
				}
				else if (vFileInformation[j] == " 30") {
					vFileInformation[j + 1] = "0.0";
				}
			}
		}

		// POINT
		if (vFileInformation[i] == "AcDbPoint") {
			for (size_t j = i + 1; vFileInformation[j] != "  0"; j++) {
				if (vFileInformation[j] == " 10") {
					vFileInformation[j + 1] = "0.0";
				}
				else if (vFileInformation[j] == " 20") {
					vFileInformation[j + 1] = "0.0";
				}
				else if (vFileInformation[j] == " 30") {
					vFileInformation[j + 1] = "0.0";
				}
			}
		}
	}

	// Äëÿ çàïèñè èçìåíåííûõ äàííûõ
	ofstream oFile("model2.dxf");

	if (!oFile.is_open()) {
		cerr << "Failed to open model2.dxf\n";

		// Êîä 2 – íå îòêðûëñÿ model2.dxf
		exit(2);
	}
	else {
		for (size_t i = 0; i < vFileInformation.size(); i++) {
			oFile << vFileInformation[i] << '\n';
		}
	}

	oFile.close();

	// Âûâîä äàííûõ î ôèãóðàõ
	for (size_t i = 0; i < vDatabase.size(); i++) {
		vDatabase[i]->print();
	}

	cout << "The amount of figures:   " << iAmountOfFigures   << '\n';
	cout << "The amount of circles:   " << iAmountOfCircles   << '\n';
	cout << "The amount of polylines: " << iAmountOfPolylines << '\n';
	cout << "The amount of ellipses:  " << iAmountOfEllipses  << '\n';
	cout << "The amount of points:    " << iAmountOfPoints    << '\n';

	del_vector(vDatabase);

	return 0;
}