Name:       lottie_test

Version:    0.0.1
Release:    1
License:    GPLv3
Source0:    %{name}-%{version}.tar.bz2

BuildRequires:  pkgconfig(sailfishapp) >= 1.0.2
BuildRequires:  pkgconfig(Qt5Quick)
BuildRequires:  pkgconfig(Qt5DBus)
BuildRequires:  desktop-file-utils
Requires: sailfishsilica-qt5 >= 0.10.9
Requires: declarative-transferengine-qt5

%description
Lottie test application

%prep
%autosetup -n %{name}-%{version}

%build
%qmake5
%make_build

%install
%qmake5_install

%files
%defattr(-,root,root,-)
%{_bindir}/%{name}
%{_datadir}/%{name}
%{_datadir}/applications/%{name}.desktop

%{_libdir}/qt5/qml/Lottie
