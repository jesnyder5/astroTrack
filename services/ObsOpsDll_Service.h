#ifndef OBSOPSDLL_SERVICE_H
#define OBSOPSDLL_SERVICE_H

// IOMOD control parameters structure
typedef struct
{
   int  printIOHG;
   int  useFirst3Obs;
   int  satNum;
   int  sortOrder;
   char satName[9];
   int  runDC;
   int  runRotas;
} IomodCtrl;


void GetIomodCtrlPara(IomodCtrl* iomodCtrl);
void PrintIomodCtrls(FILE* fpOut, IomodCtrl* iomodCtrl);

#endif
