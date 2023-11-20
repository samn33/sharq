#include "sharq.h"

int main()
{
  Sharq::QCirc qc_in;
  // random circuit (qubit-num=5, gate-num=20, X:T:CX=4:5:3)
  qc_in.load("in.sqc");

  qc_in.show(); // show the circuit
  std::cout << "T-count (in) = " << qc_in.tcount() << std::endl;

  Sharq::Optimizer opt;
  Sharq::QCirc qc_out = opt.execute(qc_in); // circuit optimization

  qc_out.show(); // show the circuit
  qc_out.save("out.sqc"); // save to text file
  std::cout << "T-count (out) = " << qc_out.tcount() << std::endl;

  return 0;
}
