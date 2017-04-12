#include <node_api.h>
#include <string.h>
void TestLatin1(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc;
  status = napi_get_cb_args_length(env, info, &argc);
  if (status != napi_ok) return;

  if (argc < 1) {
    napi_throw_type_error(env, "Wrong number of arguments");
    return;
  }

  napi_value args[1];
  status = napi_get_cb_args(env, info, args, 1);
  if (status != napi_ok) return;

  napi_valuetype valuetype;
  status = napi_typeof(env, args[0], &valuetype);
  if (status != napi_ok) return;

  if (valuetype != napi_string) {
    napi_throw_type_error(env, "Wrong type of argments. Expects a string.");
    return;
  }

  char buffer[128];
  size_t buffer_size = 128;

  size_t len = 0;
  status =
      napi_get_value_string_latin1(env, args[0], buffer, buffer_size, &len);
  if (status != napi_ok) return;

  napi_value output;
  status = napi_create_string_latin1(env, buffer, len, &output);
  if (status != napi_ok) return;

  status = napi_set_return_value(env, info, output);
  if (status != napi_ok) return;
}

void TestUtf8(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc;
  status = napi_get_cb_args_length(env, info, &argc);
  if (status != napi_ok) return;

  if (argc < 1) {
    napi_throw_type_error(env, "Wrong number of arguments");
    return;
  }

  napi_value args[1];
  status = napi_get_cb_args(env, info, args, 1);
  if (status != napi_ok) return;

  napi_valuetype valuetype;
  status = napi_typeof(env, args[0], &valuetype);
  if (status != napi_ok) return;

  if (valuetype != napi_string) {
    napi_throw_type_error(env, "Wrong type of argments. Expects a string.");
    return;
  }

  char buffer[128];
  size_t buffer_size = 128;

  size_t len = 0;
  status =
      napi_get_value_string_utf8(env, args[0], buffer, buffer_size, &len);
  if (status != napi_ok) return;

  napi_value output;
  status = napi_create_string_utf8(env, buffer, len, &output);
  if (status != napi_ok) return;

  status = napi_set_return_value(env, info, output);
  if (status != napi_ok) return;
}

void TestUtf16(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc;
  status = napi_get_cb_args_length(env, info, &argc);
  if (status != napi_ok) return;

  if (argc < 1) {
    napi_throw_type_error(env, "Wrong number of arguments");
    return;
  }

  napi_value args[1];
  status = napi_get_cb_args(env, info, args, 1);
  if (status != napi_ok) return;

  napi_valuetype valuetype;
  status = napi_typeof(env, args[0], &valuetype);
  if (status != napi_ok) return;

  if (valuetype != napi_string) {
    napi_throw_type_error(env, "Wrong type of argments. Expects a string.");
    return;
  }

  char16_t buffer[128];
  size_t buffer_size = 128;

  size_t len = 0;
  status =
      napi_get_value_string_utf16(env, args[0], buffer, buffer_size, &len);
  if (status != napi_ok) return;

  napi_value output;
  status = napi_create_string_utf16(env, buffer, len, &output);
  if (status != napi_ok) return;

  status = napi_set_return_value(env, info, output);
  if (status != napi_ok) return;
}

void TestLatin1Insufficient(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc;
  status = napi_get_cb_args_length(env, info, &argc);
  if (status != napi_ok) return;

  if (argc < 1) {
    napi_throw_type_error(env, "Wrong number of arguments");
    return;
  }

  napi_value args[1];
  status = napi_get_cb_args(env, info, args, 1);
  if (status != napi_ok) return;

  napi_valuetype valuetype;
  status = napi_typeof(env, args[0], &valuetype);
  if (status != napi_ok) return;

  if (valuetype != napi_string) {
    napi_throw_type_error(env, "Wrong type of argments. Expects a string.");
    return;
  }

  char buffer[4];
  size_t buffer_size = 4;

  size_t len = 0;
  status =
      napi_get_value_string_latin1(env, args[0], buffer, buffer_size, &len);
  if (status != napi_ok) return;

  napi_value output;
  status = napi_create_string_latin1(env, buffer, len, &output);
  if (status != napi_ok) return;

  status = napi_set_return_value(env, info, output);
  if (status != napi_ok) return;
}

void TestUtf8Insufficient(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc;
  status = napi_get_cb_args_length(env, info, &argc);
  if (status != napi_ok) return;

  if (argc < 1) {
    napi_throw_type_error(env, "Wrong number of arguments");
    return;
  }

  napi_value args[1];
  status = napi_get_cb_args(env, info, args, 1);
  if (status != napi_ok) return;

  napi_valuetype valuetype;
  status = napi_typeof(env, args[0], &valuetype);
  if (status != napi_ok) return;

  if (valuetype != napi_string) {
    napi_throw_type_error(env, "Wrong type of argments. Expects a string.");
    return;
  }

  char buffer[4];
  size_t buffer_size = 4;

  size_t len = 0;
  status =
      napi_get_value_string_utf8(env, args[0], buffer, buffer_size, &len);
  if (status != napi_ok) return;

  napi_value output;
  status = napi_create_string_utf8(env, buffer, len, &output);
  if (status != napi_ok) return;

  status = napi_set_return_value(env, info, output);
  if (status != napi_ok) return;
}

void TestUtf16Insufficient(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc;
  status = napi_get_cb_args_length(env, info, &argc);
  if (status != napi_ok) return;

  if (argc < 1) {
    napi_throw_type_error(env, "Wrong number of arguments");
    return;
  }

  napi_value args[1];
  status = napi_get_cb_args(env, info, args, 1);
  if (status != napi_ok) return;

  napi_valuetype valuetype;
  status = napi_typeof(env, args[0], &valuetype);
  if (status != napi_ok) return;

  if (valuetype != napi_string) {
    napi_throw_type_error(env, "Wrong type of argments. Expects a string.");
    return;
  }

  char16_t buffer[4];
  size_t buffer_size = 4;

  size_t len = 0;
  status =
      napi_get_value_string_utf16(env, args[0], buffer, buffer_size, &len);
  if (status != napi_ok) return;

  napi_value output;
  status = napi_create_string_utf16(env, buffer, len, &output);
  if (status != napi_ok) return;

  status = napi_set_return_value(env, info, output);
  if (status != napi_ok) return;
}

void Length(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc;
  status = napi_get_cb_args_length(env, info, &argc);
  if (status != napi_ok) return;

  if (argc < 1) {
    napi_throw_type_error(env, "Wrong number of arguments");
    return;
  }

  napi_value args[1];
  status = napi_get_cb_args(env, info, args, 1);
  if (status != napi_ok) return;

  napi_valuetype valuetype;
  status = napi_typeof(env, args[0], &valuetype);
  if (status != napi_ok) return;

  if (valuetype != napi_string) {
    napi_throw_type_error(env, "Wrong type of argments. Expects a string.");
    return;
  }

  size_t length;
  status = napi_get_value_string_length(env, args[0], &length);
  if (status != napi_ok) return;

  napi_value output;
  status = napi_create_number(env, (double)length, &output);
  if (status != napi_ok) return;

  status = napi_set_return_value(env, info, output);
  if (status != napi_ok) return;
}

void Utf8Length(napi_env env, napi_callback_info info) {
  napi_status status;

  size_t argc;
  status = napi_get_cb_args_length(env, info, &argc);
  if (status != napi_ok) return;

  if (argc < 1) {
    napi_throw_type_error(env, "Wrong number of arguments");
    return;
  }

  napi_value args[1];
  status = napi_get_cb_args(env, info, args, 1);
  if (status != napi_ok) return;

  napi_valuetype valuetype;
  status = napi_typeof(env, args[0], &valuetype);
  if (status != napi_ok) return;

  if (valuetype != napi_string) {
    napi_throw_type_error(env, "Wrong type of argments. Expects a string.");
    return;
  }

  size_t length;
  status = napi_get_value_string_utf8(env, args[0], NULL, 0, &length);
  if (status != napi_ok) return;

  napi_value output;
  status = napi_create_number(env, (double)length, &output);
  if (status != napi_ok) return;

  status = napi_set_return_value(env, info, output);
  if (status != napi_ok) return;
}

#define DECLARE_NAPI_METHOD(name, func)                          \
  { name, func, 0, 0, 0, napi_default, 0 }

void Init(napi_env env, napi_value exports, napi_value module, void* priv) {
  napi_status status;

  napi_property_descriptor properties[] = {
      DECLARE_NAPI_METHOD("TestLatin1", TestLatin1),
      DECLARE_NAPI_METHOD("TestUtf8", TestUtf8),
      DECLARE_NAPI_METHOD("TestUtf16", TestUtf16),
      DECLARE_NAPI_METHOD("TestLatin1Insufficient", TestLatin1Insufficient),
      DECLARE_NAPI_METHOD("TestUtf8Insufficient", TestUtf8Insufficient),
      DECLARE_NAPI_METHOD("TestUtf16Insufficient", TestUtf16Insufficient),
      DECLARE_NAPI_METHOD("Length", Length),
      DECLARE_NAPI_METHOD("Utf8Length", Utf8Length),
  };

  status = napi_define_properties(
      env, exports, sizeof(properties) / sizeof(*properties), properties);
  if (status != napi_ok) return;
}

NAPI_MODULE(addon, Init)
