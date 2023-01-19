#include <check.h>
#include <stdio.h>

#include "run_core_test.h"
START_TEST(test_1) {
  char str[256] = "(5+5)*1-0+((1/1))-1+tg(0)+sin(0)*cos(0)";
  double result = 0;
  run_test(str, &result);
  snprintf(str, sizeof(256), "%f", result);
  char str2[256] = {0};
  snprintf(str2, sizeof(256), "%f", 10.0);
  ck_assert_str_eq(str, str2);
}
END_TEST


START_TEST(test_2) {
  char str[256] = "ctg(1)*0 + sqrt(1) + acos(1) + asin(0) + 1mod1 + 1^2 + (-1) + -(1.00)";
  double result = 0;
  run_test(str, &result);
  snprintf(str, sizeof(256), "%f", result);

  char str2[256] = {0};
  snprintf(str2, sizeof(256), "%f", 0.000000);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_3) {
  char str[256] = "acos(1) + 123.123 - 123.123 + atan(0) + log(10)";
  double result = 0;
  run_test(str, &result);
  snprintf(str, sizeof(256), "%f", result);

  char str2[256] = {0};
  snprintf(str2, sizeof(256), "%f", 1.000000);
  ck_assert_str_eq(str, str2);
}


END_TEST
START_TEST(test_4) {
  char str[256] = "actg(0)+15/(7-(1+1))*3-(2+(1+1))";
  double result = 0;
  run_test(str, &result);
  snprintf(str, sizeof(256), "%f", result);
  char str2[256] = {0};
  snprintf(str2, sizeof(256), "%f", 0.197396);
  ck_assert_str_eq(str, str2);
}

START_TEST(test_5) {
  char str[256] = "";
  double result = 0;
  run_test(str, &result);
  snprintf(str, sizeof(256), "%f", result);
  char str2[256] = {0};
  snprintf(str2, sizeof(256), "%f", 0.000000);
  ck_assert_str_eq(str, str2);
}

int main() {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, test_1);
  tcase_add_test(tc1_1, test_2);
  tcase_add_test(tc1_1, test_3);
  tcase_add_test(tc1_1, test_4);
  tcase_add_test(tc1_1, test_5);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
