#include "TriageSystem.h"
using namespace std;

const string TREATMENTS_FILE = "treatments.txt";

int main() {
  TriageSystem triage;
  triage.LoadCatalog(TREATMENTS_FILE);
  triage.Run();
  return 0;
}
