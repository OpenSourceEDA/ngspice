/**********
Copyright 1990 Regents of the University of California.  All rights reserved.
Author: 1985 Thomas L. Quarles
Modified: Alan Gillespie
**********/

/* Pretty print the sensitivity info for all 
 * the bjt2s in the circuit.
 */

#include "ngspice.h"
#include <stdio.h>
#include "cktdefs.h"
#include "smpdefs.h"
#include "bjt2defs.h"
#include "const.h"
#include "sperror.h"
#include "ifsim.h"
#include "suffix.h"


void
BJT2sPrint(inModel,ckt)

CKTcircuit *ckt;
GENmodel *inModel;
{
    BJT2model *model = (BJT2model*)inModel;
    BJT2instance *here;

    printf("BJT2S-----------------\n");
    /*  loop through all the BJT2 models */
    for( ; model != NULL; model = model->BJT2nextModel ) {

        printf("Model name:%s\n",model->BJT2modName);

        /* loop through all the instances of the model */
        for (here = model->BJT2instances; here != NULL ;
                here=here->BJT2nextInstance) {
            ckt->CKTsenInfo->SEN_parmVal[here->BJT2senParmNo] = here->BJT2area;

            printf("    Instance name:%s\n",here->BJT2name);
            printf("      Collector, Base , Emitter nodes: %s, %s ,%s\n",
            CKTnodName(ckt,here->BJT2colNode),CKTnodName(ckt,here->BJT2baseNode),
            CKTnodName(ckt,here->BJT2emitNode));

            printf("      Area: %g ",here->BJT2area);
            printf(here->BJT2areaGiven ? "(specified)\n" : "(default)\n");
            printf("    BJT2senParmNo:%d\n",here->BJT2senParmNo);

        }
    }
}

