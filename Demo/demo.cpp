#include "mzParser.h"
#include "MSObject.h"
#include "mzMLWriter.h"

using namespace std;
using namespace mzParser;
using namespace MSToolkit;

//int main(int argc, char* argv[]) {
//
//	if (argc != 2) {
//		cout << "USAGE: mzMLReader <mzML file>" << endl;
//		exit(0);
//	}
//
//	MSDataFile* msd;
//	ChromatogramListPtr sl;
//	ChromatogramPtr s2;
//	string st = argv[1];
//	vector<TimeIntensityPair> pairs;
//
//	msd = new MSDataFile(argv[1]);
//	if (!msd->run.chromatogramListPtr->get()) cout << "WTF" << endl;
//
//	sl = msd->run.chromatogramListPtr;
//	for (int j = 1; j < (int)sl->size(); j++) {
//		s2 = sl->chromatogram(j, true);
//		cout << j << "\t" << s2->id << endl;
//		s2->getTimeIntensityPairs(pairs);
//		for (int k = 0; k < (int)pairs.size(); k++) cout << pairs[k].time << " " << pairs[k].intensity << endl;
//	}
//
//
//	//exit(1);
//
//	BasicSpectrum s;
//	BasicChromatogram chromat;
//	MzParser sax(&s, &chromat);
//	sax.load(argv[1]);
//
//	bool bLastWasSpectrum = true;
//	char c = 'a';
//	char str[256];
//	int num;
//	while (c != 'x') {
//
//		if (bLastWasSpectrum) {
//			cout << "\nCurrent spectrum:" << endl;
//			cout << "\tScan number: " << s.getScanNum() << endl;
//			cout << "\tRetention Time: " << s.getRTime() << endl;
//			cout << "\tMS Level: " << s.getMSLevel() << endl;
//			cout << "\tNumber of Peaks: " << s.size() << endl;
//		}
//		else {
//			chromat.getIDString(str);
//			cout << "\nCurrent chromatogram:" << endl;
//			cout << "\tID: " << str << endl;
//			cout << "\tNumber of Peaks: " << chromat.size() << endl;
//		}
//		cout << "\nMenu:\n\t'c' to grab a new chromatogram\n\t's' to grab a new spectrum\n\t'p' to show peaks\n\t'x' to exit" << endl;
//		cout << "Please enter your choice: ";
//		cin >> c;
//
//		switch (c) {
//		case 'c':
//			if (sax.highChromat() == 0) {
//				cout << "No chromatograms in the file." << endl;
//			}
//			else {
//				cout << "Enter a number from 0 to " << sax.highChromat() - 1 << ": ";
//				cin >> str;
//				num = (int)atoi(str);
//				if (num<0 || num>sax.highChromat() - 1) {
//					cout << "Bad number! BOOOOO!" << endl;
//				}
//				else {
//					if (!sax.readChromatogram(num)) cout << "Chromatogram number not in file." << endl;
//					else bLastWasSpectrum = false;
//				}
//			}
//			break;
//		case 'p':
//			if (bLastWasSpectrum) {
//				MzMLWriter writer;
//				MSObject object;
//				MSToolkit::Spectrum spectrum;
//				char fileName[] = "test.mzML";
//				writer.createMzML(fileName);
//				writer.setTabs(true);
//				writer.createList();
//
//				for (unsigned int i = 0; i < s.size(); i++)
//				{
//					printf("%.6lf\t%.1lf\n", s[i].mz, s[i].intensity);
//					spectrum.add(s[i].mz, s[i].intensity);
//				}
//			
//				writer.writeSpectra(spectrum);
//				writer.closeList();
//				writer.closeMzML();
//			}
//			else {
//				for (unsigned int i = 0; i < chromat.size(); i++) printf("%.6lf\t%.1lf\n", chromat[i].time, chromat[i].intensity);
//			}
//			break;
//		case 's':
//			cout << "Enter a number from " << sax.lowScan() << " to " << sax.highScan() << ": ";
//			cin >> str;
//			num = (int)atoi(str);
//			if (num<sax.lowScan() || num>sax.highScan()) {
//				cout << "Bad number! BOOOOO!" << endl;
//			}
//			else {
//				if (!sax.readSpectrum(num)) cout << "Spectrum number not in file." << endl;
//				else bLastWasSpectrum = true;
//			}
//			break;
//		case 'x':
//			break;
//		default:
//			cout << "\nInvalid command!" << endl;
//			break;
//		}
//	}
//
//
//	return 0;
//}


// IMS Writer;
//int main(int argc, char* argv[])
//{
//	MzMLWriter writer;
//	MSObject object;
//	for (int i = 0; i < 10; i++)
//	{
//		MSToolkit::Spectrum spectrum;
//		spectrum.setRTime(i < 5 ? 0 : 1);
//		double sum = 0;
//		for (int mz = 0; mz < 100; mz++)
//		{
//			const double intens = exp(-pow(mz - i * 5 - 10, 2))*100.0;
//			sum += intens;
//			spectrum.add(mz, intens);
//		}
//		spectrum.setIonMobility(i % 5 + 0.1);
//		spectrum.setScanNumber(i);
//		spectrum.setMsLevel(1);
//		spectrum.setSelWindow(0, 100);
//		spectrum.setScanWindow(0, 100);
//		spectrum.setTIC(sum);
//		object.add(spectrum);
//	}
//	char fileName[] = "test.mzml";
//	writer.createMzML(fileName);
//	writer.createList();
//	writer.writeSpectra(object);
//	writer.closeList();
//	writer.closeMzML();
//	return 0;
//}

int main(int argc, char* argv[])
{
	MzMLWriter writer;
	MSObject object;
	
	for (int i = 0; i < 10; i++)
	{
		MSToolkit::Spectrum spectrum;
		spectrum.setRTime(0);
		double sum = 0;
		for (int mz = 0; mz < 100; mz++)
		{
			const double intens = exp(-pow(mz - i * 5 - 10, 2)) * 100.0;
			sum += intens;
			spectrum.add(mz, intens);
		}
		spectrum.setIonMobility(i % 5 + 0.1);
		spectrum.setScanNumber(i);
		spectrum.setMsLevel(1);
		spectrum.setSelWindow(0, 100);
		spectrum.setScanWindow(0, 100);
		spectrum.setTIC(sum);
		object.add(spectrum);
	}
	char fileName[] = "test.mzml";
	writer.createMzML(fileName);
	writer.createList();
	writer.writeSpectra(object);
	writer.closeList();
	writer.closeMzML();
	return 0;
}