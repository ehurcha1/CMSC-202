CXX = g++
CXXFLAGS = -Wall

proj3: proj3.cpp TriageSystem.o Patient.o TreatmentList.o PatientTreatment.o TreatmentCatalog.o Treatment.o Node.h
	$(CXX) $(CXXFLAGS) TriageSystem.o proj3.cpp Patient.o TreatmentList.o PatientTreatment.o Node.h TreatmentCatalog.o Treatment.o -o proj3

TriageSystem.o: TriageSystem.h TriageSystem.cpp TreatmentCatalog.o Patient.o TreatmentList.o PatientTreatment.o
	$(CXX) $(CXXFLAGS) -c TriageSystem.cpp

Patient.o: Patient.h Patient.cpp
	$(CXX) $(CXXFLAGS) -c Patient.cpp

TreatmentList.o: TreatmentList.h TreatmentList.cpp PatientTreatment.o Node.h
	$(CXX) $(CXXFLAGS) -c TreatmentList.cpp

PatientTreatment.o: PatientTreatment.h PatientTreatment.cpp
	$(CXX) $(CXXFLAGS) -c PatientTreatment.cpp

TreatmentCatalog.o: TreatmentCatalog.h TreatmentCatalog.cpp
	$(CXX) $(CXXFLAGS) -c TreatmentCatalog.cpp

Treatment.o: Treatment.h Treatment.cpp
	$(CXX) $(CXXFLAGS) -c Treatment.cpp

run:
	./proj3

clean:
	rm *.o
	rm *~

val:
	valgrind ./proj3

submit:
	cp proj3.cpp TriageSystem.h TriageSystem.cpp Patient.h Patient.cpp TreatmentList.h TreatmentList.cpp PatientTreatment.h PatientTreatment.cpp TreatmentCatalog.h TreatmentCatalog.cpp Treatment.h Treatment.cpp Node.h ~/cs202proj/proj3
