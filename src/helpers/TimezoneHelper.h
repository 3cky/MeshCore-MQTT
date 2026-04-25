#pragma once
#include <Timezone.h>

// Returns a heap-allocated Timezone for the given IANA/abbreviation/offset string,
// or nullptr if unrecognized. Caller owns the returned object.
static inline Timezone* createTimezoneFromString(const char* tz_string) {
  if (!tz_string || tz_string[0] == '\0') return nullptr;

  // North America
  if (strcmp(tz_string, "America/Los_Angeles") == 0 || strcmp(tz_string, "America/Vancouver") == 0) {
    TimeChangeRule pst = {"PST", First, Sun, Nov, 2, -480};
    TimeChangeRule pdt = {"PDT", Second, Sun, Mar, 2, -420};
    return new Timezone(pdt, pst);
  } else if (strcmp(tz_string, "America/Denver") == 0) {
    TimeChangeRule mst = {"MST", First, Sun, Nov, 2, -420};
    TimeChangeRule mdt = {"MDT", Second, Sun, Mar, 2, -360};
    return new Timezone(mdt, mst);
  } else if (strcmp(tz_string, "America/Chicago") == 0) {
    TimeChangeRule cst = {"CST", First, Sun, Nov, 2, -360};
    TimeChangeRule cdt = {"CDT", Second, Sun, Mar, 2, -300};
    return new Timezone(cdt, cst);
  } else if (strcmp(tz_string, "America/New_York") == 0 || strcmp(tz_string, "America/Toronto") == 0) {
    TimeChangeRule est = {"EST", First, Sun, Nov, 2, -300};
    TimeChangeRule edt = {"EDT", Second, Sun, Mar, 2, -240};
    return new Timezone(edt, est);
  } else if (strcmp(tz_string, "America/Anchorage") == 0) {
    TimeChangeRule akst = {"AKST", First, Sun, Nov, 2, -540};
    TimeChangeRule akdt = {"AKDT", Second, Sun, Mar, 2, -480};
    return new Timezone(akdt, akst);
  } else if (strcmp(tz_string, "Pacific/Honolulu") == 0) {
    TimeChangeRule hst = {"HST", Last, Sun, Oct, 2, -600};
    return new Timezone(hst, hst);

  // Europe
  } else if (strcmp(tz_string, "Europe/London") == 0) {
    TimeChangeRule gmt = {"GMT", Last, Sun, Oct, 2, 0};
    TimeChangeRule bst = {"BST", Last, Sun, Mar, 1, 60};
    return new Timezone(bst, gmt);
  } else if (strcmp(tz_string, "Europe/Paris") == 0 || strcmp(tz_string, "Europe/Berlin") == 0) {
    TimeChangeRule cet = {"CET", Last, Sun, Oct, 3, 60};
    TimeChangeRule cest = {"CEST", Last, Sun, Mar, 2, 120};
    return new Timezone(cest, cet);
  } else if (strcmp(tz_string, "Europe/Moscow") == 0) {
    TimeChangeRule msk = {"MSK", Last, Sun, Oct, 3, 180};
    return new Timezone(msk, msk);

  // Asia
  } else if (strcmp(tz_string, "Asia/Tokyo") == 0) {
    TimeChangeRule jst = {"JST", Last, Sun, Oct, 2, 540};
    return new Timezone(jst, jst);
  } else if (strcmp(tz_string, "Asia/Shanghai") == 0 || strcmp(tz_string, "Asia/Hong_Kong") == 0) {
    TimeChangeRule cst = {"CST", Last, Sun, Oct, 2, 480};
    return new Timezone(cst, cst);
  } else if (strcmp(tz_string, "Asia/Kolkata") == 0) {
    TimeChangeRule ist = {"IST", Last, Sun, Oct, 2, 330};
    return new Timezone(ist, ist);
  } else if (strcmp(tz_string, "Asia/Dubai") == 0) {
    TimeChangeRule gst = {"GST", Last, Sun, Oct, 2, 240};
    return new Timezone(gst, gst);

  // Australia
  } else if (strcmp(tz_string, "Australia/Sydney") == 0 || strcmp(tz_string, "Australia/Melbourne") == 0) {
    TimeChangeRule aest = {"AEST", First, Sun, Apr, 3, 600};
    TimeChangeRule aedt = {"AEDT", First, Sun, Oct, 2, 660};
    return new Timezone(aedt, aest);
  } else if (strcmp(tz_string, "Australia/Perth") == 0) {
    TimeChangeRule awst = {"AWST", Last, Sun, Oct, 2, 480};
    return new Timezone(awst, awst);

  // Abbreviations
  } else if (strcmp(tz_string, "PDT") == 0 || strcmp(tz_string, "PST") == 0) {
    TimeChangeRule pst = {"PST", First, Sun, Nov, 2, -480};
    TimeChangeRule pdt = {"PDT", Second, Sun, Mar, 2, -420};
    return new Timezone(pdt, pst);
  } else if (strcmp(tz_string, "MDT") == 0 || strcmp(tz_string, "MST") == 0) {
    TimeChangeRule mst = {"MST", First, Sun, Nov, 2, -420};
    TimeChangeRule mdt = {"MDT", Second, Sun, Mar, 2, -360};
    return new Timezone(mdt, mst);
  } else if (strcmp(tz_string, "CDT") == 0 || strcmp(tz_string, "CST") == 0) {
    TimeChangeRule cst = {"CST", First, Sun, Nov, 2, -360};
    TimeChangeRule cdt = {"CDT", Second, Sun, Mar, 2, -300};
    return new Timezone(cdt, cst);
  } else if (strcmp(tz_string, "EDT") == 0 || strcmp(tz_string, "EST") == 0) {
    TimeChangeRule est = {"EST", First, Sun, Nov, 2, -300};
    TimeChangeRule edt = {"EDT", Second, Sun, Mar, 2, -240};
    return new Timezone(edt, est);
  } else if (strcmp(tz_string, "BST") == 0 || strcmp(tz_string, "GMT") == 0) {
    TimeChangeRule gmt = {"GMT", Last, Sun, Oct, 2, 0};
    TimeChangeRule bst = {"BST", Last, Sun, Mar, 1, 60};
    return new Timezone(bst, gmt);
  } else if (strcmp(tz_string, "CEST") == 0 || strcmp(tz_string, "CET") == 0) {
    TimeChangeRule cet = {"CET", Last, Sun, Oct, 3, 60};
    TimeChangeRule cest = {"CEST", Last, Sun, Mar, 2, 120};
    return new Timezone(cest, cet);
  } else if (strcmp(tz_string, "AEST") == 0 || strcmp(tz_string, "AEDT") == 0) {
    TimeChangeRule aest = {"AEST", First, Sun, Apr, 3, 600};
    TimeChangeRule aedt = {"AEDT", First, Sun, Oct, 2, 660};
    return new Timezone(aedt, aest);

  // UTC and offset formats
  } else if (strcmp(tz_string, "UTC") == 0 || strcmp(tz_string, "Etc/UTC") == 0) {
    TimeChangeRule utc = {"UTC", Last, Sun, Mar, 0, 0};
    return new Timezone(utc, utc);
  } else if (strncmp(tz_string, "UTC", 3) == 0) {
    int offset = atoi(tz_string + 3);
    TimeChangeRule r = {"UTC", Last, Sun, Mar, 0, offset * 60};
    return new Timezone(r, r);
  } else if (strncmp(tz_string, "GMT", 3) == 0) {
    int offset = atoi(tz_string + 3);
    TimeChangeRule r = {"GMT", Last, Sun, Mar, 0, offset * 60};
    return new Timezone(r, r);
  } else if (tz_string[0] == '+' || tz_string[0] == '-') {
    int offset = atoi(tz_string);
    TimeChangeRule r = {"TZ", Last, Sun, Mar, 0, offset * 60};
    return new Timezone(r, r);
  }

  return nullptr;
}
