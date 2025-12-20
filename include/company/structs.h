// Struct Company Registration

struct CompanyRegistration {
    char companyCode[5];
    char companyName[50];
    char userAdmin[15];
    char passwordAdmin[10];
    int levelAccess;
};

typedef struct CompanyRegistration CompanyRegistration;