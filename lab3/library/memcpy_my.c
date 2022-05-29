void memcpy_my(char *s_to, const char *s_from, int n) {
    for (size_t i = 0; i < n; i++) {
        *(s_to + i) = *(s_from + i);
    }
}
