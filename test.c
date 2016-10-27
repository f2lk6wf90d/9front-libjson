#include "json.h"
#include <stdio.h>

int main(void) {
  FILE* testf = fopen("test.json", "r");
  char* buffer = NULL;
  size_t len;
  ssize_t bytes_read;
  if(testf) {
    bytes_read = getdelim(&buffer, &len, '\0', testf);
    fclose(testf);
  }
  if(bytes_read != -1) {
    JSON* jsonobj = jsonparse(buffer);
    if(jsonobj->t != JSONObject) {
      return -1;
    }
    for(JSONEl* elem = jsonobj->first; elem != NULL; elem = elem->next) {
      printf("The current element's name is %s\n", elem->name);
      switch(elem->val->t) {
        case JSONString:
          printf("Value: %s\n", elem->val->s);
          break;
        case JSONNumber:
          printf("Value: %f\n", elem->val->n);
          break;
      }
    }
  }
}
