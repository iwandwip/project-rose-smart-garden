// Trapezoidal Member Function
FIS_TYPE fis_trapmf(FIS_TYPE x, FIS_TYPE* p) {
        FIS_TYPE a = p[0], b = p[1], c = p[2], d = p[3];
        FIS_TYPE t1 = ((x <= c) ? 1 : ((d < x) ? 0 : ((c != d) ? ((d - x) / (d - c)) : 0)));
        FIS_TYPE t2 = ((b <= x) ? 1 : ((x < a) ? 0 : ((a != b) ? ((x - a) / (b - a)) : 0)));
        return (FIS_TYPE)min(t1, t2);
}

// Triangular Member Function
FIS_TYPE fis_trimf(FIS_TYPE x, FIS_TYPE* p) {
        FIS_TYPE a = p[0], b = p[1], c = p[2];
        FIS_TYPE t1 = (x - a) / (b - a);
        FIS_TYPE t2 = (c - x) / (c - b);
        if ((a == b) && (b == c)) return (FIS_TYPE)(x == a);
        if (a == b) return (FIS_TYPE)(t2 * (b <= x) * (x <= c));
        if (b == c) return (FIS_TYPE)(t1 * (a <= x) * (x <= b));
        t1 = min(t1, t2);
        return (FIS_TYPE)max(t1, 0);
}

FIS_TYPE fis_min(FIS_TYPE a, FIS_TYPE b) {
        return min(a, b);
}

FIS_TYPE fis_max(FIS_TYPE a, FIS_TYPE b) {
        return max(a, b);
}

FIS_TYPE fis_array_operation(FIS_TYPE* array, int size, _FIS_ARR_OP pfnOp) {
        int i;
        FIS_TYPE ret = 0;

        if (size == 0) return ret;
        if (size == 1) return array[0];

        ret = array[0];
        for (i = 1; i < size; i++) {
                ret = (*pfnOp)(ret, array[i]);
        }

        return ret;
}


//***********************************************************************
// Data for Fuzzy Inference System
//***********************************************************************
// Pointers to the implementations of member functions
_FIS_MF fis_gMF[] = {
        fis_trapmf, fis_trimf
};

// Count of member function for each Input
int fis_gIMFCount[] = { 3, 3 };

// Count of member function for each Output
int fis_gOMFCount[] = { 3 };

// Coefficients for the Input Member Functions
FIS_TYPE fis_gMFI0Coeff1[] = { -20, -10, 60, 70 };
FIS_TYPE fis_gMFI0Coeff2[] = { 64.922898997687, 69.922898997687, 74.922898997687 };
FIS_TYPE fis_gMFI0Coeff3[] = { 70, 80, 110, 120 };
FIS_TYPE* fis_gMFI0Coeff[] = { fis_gMFI0Coeff1, fis_gMFI0Coeff2, fis_gMFI0Coeff3 };
FIS_TYPE fis_gMFI1Coeff1[] = { -20, -10, 18, 23 };
FIS_TYPE fis_gMFI1Coeff2[] = { 18, 23, 28 };
FIS_TYPE fis_gMFI1Coeff3[] = { 23, 28, 50, 60 };
FIS_TYPE* fis_gMFI1Coeff[] = { fis_gMFI1Coeff1, fis_gMFI1Coeff2, fis_gMFI1Coeff3 };
FIS_TYPE** fis_gMFICoeff[] = { fis_gMFI0Coeff, fis_gMFI1Coeff };

// Coefficients for the Output Member Functions
FIS_TYPE fis_gMFO0Coeff1[] = { 0, 0, 25, 50 };
FIS_TYPE fis_gMFO0Coeff2[] = { 25, 50, 75 };
FIS_TYPE fis_gMFO0Coeff3[] = { 50, 75, 100, 100 };
FIS_TYPE* fis_gMFO0Coeff[] = { fis_gMFO0Coeff1, fis_gMFO0Coeff2, fis_gMFO0Coeff3 };
FIS_TYPE** fis_gMFOCoeff[] = { fis_gMFO0Coeff };

// Input membership function set
int fis_gMFI0[] = { 0, 1, 0 };
int fis_gMFI1[] = { 0, 1, 0 };
int* fis_gMFI[] = { fis_gMFI0, fis_gMFI1 };

// Output membership function set
int fis_gMFO0[] = { 0, 1, 0 };
int* fis_gMFO[] = { fis_gMFO0 };

// Rule Weights
FIS_TYPE fis_gRWeight[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };

// Rule Type
int fis_gRType[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };

// Rule Inputs
int fis_gRI0[] = { 1, 3 };
int fis_gRI1[] = { 2, 3 };
int fis_gRI2[] = { 3, 3 };
int fis_gRI3[] = { 1, 2 };
int fis_gRI4[] = { 2, 2 };
int fis_gRI5[] = { 3, 2 };
int fis_gRI6[] = { 1, 1 };
int fis_gRI7[] = { 2, 1 };
int fis_gRI8[] = { 3, 1 };
int* fis_gRI[] = { fis_gRI0, fis_gRI1, fis_gRI2, fis_gRI3, fis_gRI4, fis_gRI5, fis_gRI6, fis_gRI7, fis_gRI8 };

// Rule Outputs
int fis_gRO0[] = { 2 };
int fis_gRO1[] = { 2 };
int fis_gRO2[] = { 3 };
int fis_gRO3[] = { 1 };
int fis_gRO4[] = { 2 };
int fis_gRO5[] = { 3 };
int fis_gRO6[] = { 2 };
int fis_gRO7[] = { 2 };
int fis_gRO8[] = { 3 };
int* fis_gRO[] = { fis_gRO0, fis_gRO1, fis_gRO2, fis_gRO3, fis_gRO4, fis_gRO5, fis_gRO6, fis_gRO7, fis_gRO8 };

// Input range Min
FIS_TYPE fis_gIMin[] = { 0, 0 };

// Input range Max
FIS_TYPE fis_gIMax[] = { 100, 40 };

// Output range Min
FIS_TYPE fis_gOMin[] = { 0 };

// Output range Max
FIS_TYPE fis_gOMax[] = { 100 };

//***********************************************************************
// Data dependent support functions for Fuzzy Inference System
//***********************************************************************
FIS_TYPE fis_MF_out(FIS_TYPE** fuzzyRuleSet, FIS_TYPE x, int o) {
        FIS_TYPE mfOut;
        int r;

        for (r = 0; r < fis_gcR; ++r) {
                int index = fis_gRO[r][o];
                if (index > 0) {
                        index = index - 1;
                        mfOut = (fis_gMF[fis_gMFO[o][index]])(x, fis_gMFOCoeff[o][index]);
                } else if (index < 0) {
                        index = -index - 1;
                        mfOut = 1 - (fis_gMF[fis_gMFO[o][index]])(x, fis_gMFOCoeff[o][index]);
                } else {
                        mfOut = 0;
                }

                fuzzyRuleSet[0][r] = fis_min(mfOut, fuzzyRuleSet[1][r]);
        }
        return fis_array_operation(fuzzyRuleSet[0], fis_gcR, fis_max);
}

FIS_TYPE fis_defuzz_centroid(FIS_TYPE** fuzzyRuleSet, int o) {
        FIS_TYPE step = (fis_gOMax[o] - fis_gOMin[o]) / (FIS_RESOLUSION - 1);
        FIS_TYPE area = 0;
        FIS_TYPE momentum = 0;
        FIS_TYPE dist, slice;
        int i;

        // calculate the area under the curve formed by the MF outputs
        for (i = 0; i < FIS_RESOLUSION; ++i) {
                dist = fis_gOMin[o] + (step * i);
                slice = step * fis_MF_out(fuzzyRuleSet, dist, o);
                area += slice;
                momentum += slice * dist;
        }

        return ((area == 0) ? ((fis_gOMax[o] + fis_gOMin[o]) / 2) : (momentum / area));
}

//***********************************************************************
// Fuzzy Inference System
//***********************************************************************
void fis_evaluate() {
        FIS_TYPE fuzzyInput0[] = { 0, 0, 0 };
        FIS_TYPE fuzzyInput1[] = { 0, 0, 0 };
        FIS_TYPE* fuzzyInput[fis_gcI] = {
                fuzzyInput0,
                fuzzyInput1,
        };
        FIS_TYPE fuzzyOutput0[] = { 0, 0, 0 };
        FIS_TYPE* fuzzyOutput[fis_gcO] = {
                fuzzyOutput0,
        };
        FIS_TYPE fuzzyRules[fis_gcR] = { 0 };
        FIS_TYPE fuzzyFires[fis_gcR] = { 0 };
        FIS_TYPE* fuzzyRuleSet[] = { fuzzyRules, fuzzyFires };
        FIS_TYPE sW = 0;

        // Transforming input to fuzzy Input
        int i, j, r, o;
        for (i = 0; i < fis_gcI; ++i) {
                for (j = 0; j < fis_gIMFCount[i]; ++j) {
                        fuzzyInput[i][j] =
                          (fis_gMF[fis_gMFI[i][j]])(g_fisInput[i], fis_gMFICoeff[i][j]);
                }
        }

        int index = 0;
        for (r = 0; r < fis_gcR; ++r) {
                if (fis_gRType[r] == 1) {
                        fuzzyFires[r] = FIS_MAX;
                        for (i = 0; i < fis_gcI; ++i) {
                                index = fis_gRI[r][i];
                                if (index > 0)
                                        fuzzyFires[r] = fis_min(fuzzyFires[r], fuzzyInput[i][index - 1]);
                                else if (index < 0)
                                        fuzzyFires[r] = fis_min(fuzzyFires[r], 1 - fuzzyInput[i][-index - 1]);
                                else
                                        fuzzyFires[r] = fis_min(fuzzyFires[r], 1);
                        }
                } else {
                        fuzzyFires[r] = FIS_MIN;
                        for (i = 0; i < fis_gcI; ++i) {
                                index = fis_gRI[r][i];
                                if (index > 0)
                                        fuzzyFires[r] = fis_max(fuzzyFires[r], fuzzyInput[i][index - 1]);
                                else if (index < 0)
                                        fuzzyFires[r] = fis_max(fuzzyFires[r], 1 - fuzzyInput[i][-index - 1]);
                                else
                                        fuzzyFires[r] = fis_max(fuzzyFires[r], 0);
                        }
                }

                fuzzyFires[r] = fis_gRWeight[r] * fuzzyFires[r];
                sW += fuzzyFires[r];
        }

        if (sW == 0) {
                for (o = 0; o < fis_gcO; ++o) {
                        g_fisOutput[o] = ((fis_gOMax[o] + fis_gOMin[o]) / 2);
                }
        } else {
                for (o = 0; o < fis_gcO; ++o) {
                        g_fisOutput[o] = fis_defuzz_centroid(fuzzyRuleSet, o);
                }
        }
}
