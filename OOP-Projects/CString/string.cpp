#include "string.h"
#include <string.h>

CString::CString() : TArchive<char>() {}
CString::CString(const CString& str) : TArchive<char>(str._data, str._size) {}
CString::CString(const char* c_str) : TArchive<char>(c_str, strlen(c_str)) {}
CString::CString(const char* c_str, size_t n) : TArchive<char>(c_str, n) {}
CString::CString(size_t n, char c) : TArchive<char>(n, c) {}
CString::CString(const CString& str, size_t pos, size_t len) : TArchive<char>(str, pos, len) {}

// FIXME: illegal hardware instruction
std::ostream& operator<<(std::ostream& cout, CString str) {
    for (size_t i = 0; i < str.length(); i++) {
        IC(str.get(i));
        cout << str.get(i);
    }
    return cout;
}

CString CString::substr(size_t pos, size_t len) const {
return CString(*this, pos, len);
}

// TODO:
// Ask later what the hell if delete this, 
// inheritanced method will work but won't
void CString::clear() {
    for (size_t i = 0; i < _size; i++)
        _states[i] = State::deleted;
    _deleted = _size;
}
// /// <summary>
// /// ����������.
// /// </summary>
// CString::~CString() {
//     delete[] _data;
//     _data = nullptr;
// }

/// <summary>
/// �������� ������ �� �������.
/// </summary>
/// <returns>
/// true - ���� ������ �����,
/// false - �����.
/// </returns>
bool CString::empty() const noexcept {
    return _size == 0;
}

/// <summary>
/// ������ ��� ������� ������.
/// </summary>
/// <returns>������ (�����) ������</returns>
size_t CString::size() const noexcept {
    return _size;
}
/// <summary>
/// ������� ��������� (�������������������).
/// </summary>
/// <param name="str"> - ������ ��� ���������</param>
/// <returns>
/// 1 - ���� �������� ������ ������,
/// -1 - ���� �������� ������ ������,
/// 0 - ���� ������ ���������.
/// </returns>
int CString::compare(const CString& str) const noexcept {
    for (size_t i = 0; i < algorithms::min(_size, str._size); i++) {
        if (this->_data[i] < str._data[i]) {
            return 1;
        }
        else if (this->_data[i] > str._data[i]) {
            return -1;
        }
    }
    if (this->_size > str._size) return 1;
    else if (this->_size < str._size) return -1;
    else return 0;
}

/*
/// <summary>
/// ������� ������� � ����� ������.
/// </summary>
/// <param name="c"> - ������ ��� �������</param>
void CString::push_back(char c) {
    if (this->full()) {
        this->reserve(_capacity);
    }

    _data[_size] = c;
    _data[++_size] = '\0';
}*/

/// <summary>
/// �������� ������� �� ����� ������.
/// <exception cref="std::logic_error">����������, ���� �������� ������ �����.</exception>
/// </summary>
void CString::pop_back() {
    if (this->empty()) {
        throw std::logic_error("Error in function \
                  \"void pop_back()\": source CString is empty");
    }
    _data[--_size] = '\0';
}

/*
// ���� ������ ����������
/// <summary>
/// ������� ������ ����� �������� ������� � ��������.
/// </summary>
/// <param name="pos"> - ������� ��� ������� � �������� ������.</param>
/// <param name="str"> - ������ ��� �������</param>
/// <returns>��������� �������� ������</returns>
CString& CString::insert(size_t pos, const CString& str) {
    CString begin(*this, 0, pos);
    CString end(*this, pos, _size - pos);
    begin.append(str);
    begin.append(end);
    this->swap(begin);
    return *this;
}*/

/// <summary>
/// ����� ������� ���������� � �������� ������ � ����� �� �������� �������� ������.
/// </summary>
/// <param name="str"> - ����� �������� ��� ������</param>
/// <param name="pos"> - �������, � ������� ������� �������� �����</param>
/// <returns></returns>
size_t CString::find_first_of(const CString& str, size_t pos) const {
    for (size_t i = pos; i < _size; i++) {
        for (size_t j = 0; j < str._size; j++) {
            if (_data[i] == str._data[j]) {
                return i;
            }
        }
    }
    return -1;
}
