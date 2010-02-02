Name:           yuma
Version:        0.10
Release:        1%{?dist}
Summary:        YANG-based Unified Modular Automation Tools

Group:          Development/Tools
License:        IWL
URL:            http://yuma.iwl.com/
Source0:        %{name}-%{version}.tar.gz
BuildRoot:      %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)

%description
Yuma Tools is a YANG-based NETCONF-over-SSH client and server
development toolkit.  The netconfd server includes an automated
central NETCONF protocol stack, based directly on YANG modules.
The yangdump and yangdiff development tools are also
included, to compile and process YANG modules.

%package shlibs

Summary:  YANG-based Unified Modular Automation Tools (shared libs)
Requires: libxml2


%description shlibs
Yuma Tools is a YANG-based NETCONF-over-SSH client and server
development toolkit.  This package contains the libncx shared library.

%files shlibs
%defattr(-,root,root,-)
%{_libdir}/libncx*
/usr/share/doc/yuma/yumatools-cs-license.pdf
/usr/share/doc/yuma/yumatools-legal-notices.pdf
/usr/share/doc/yuma/AUTHORS
/usr/share/doc/yuma/ChangeLog
/usr/share/doc/yuma/README
%{_datadir}/yuma/modules/ietf/*
%{_datadir}/yuma/modules/netconfcentral/yuma-app-common.yang
%{_datadir}/yuma/modules/netconfcentral/yuma-ncx.yang
%{_datadir}/yuma/modules/netconfcentral/yuma-types.yang
%{_datadir}/yuma/modules/netconfcentral/yuma-xsd.yang
%{_datadir}/yuma/modules/test/*
%{_datadir}/yuma/modules/yang/*

%package client

Summary: YANG-based Unified Modular Automation Tools (client-side)
Group:          Development/Tools
License:        BSD

Requires: ncurses
Requires: libssh2
Requires: libxml2
Requires: shlibs

%description client
Yuma Tools (client only) is a YANG-based NETCONF-over-SSH 
client application, which provides a CLI-like interface
for any NETCONF server that supports YANG modules.
The yangdump and yangdiff development tools are also
included, to compile and process YANG modules.

%prep
%setup -q

%build
cd libtecla
./configure --prefix=$RPM_BUILD_ROOT 
cd ..
make FREE=1 RELEASE=1 %{?_smp_mflags}

%install
rm -rf $RPM_BUILD_ROOT
make install LDFLAGS+=--build-id FREE=1 RELEASE=1 \
DESTDIR=$RPM_BUILD_ROOT

%post
ldconfig
echo "Yuma client: yangcli, yangdump, and yangdiff installed"
echo "Check the user manuals in /etc/share/doc/yuma"
echo "or type 'man <program name>' for instructions on usage."

%clean
rm -rf $RPM_BUILD_ROOT

%files client
%defattr(-,root,root,-)
%{_bindir}/yangcli
%{_bindir}/yangdump
%{_bindir}/yangdiff
%{_sysconfdir}/yuma/yangcli-sample.conf
%{_sysconfdir}/yuma/yangdiff-sample.conf
%{_sysconfdir}/yuma/yangdump-sample.conf
/usr/share/doc/yuma/yumatools-cs-license.pdf
/usr/share/doc/yuma/yumatools-legal-notices.pdf
/usr/share/doc/yuma/AUTHORS
/usr/share/doc/yuma/ChangeLog
/usr/share/doc/yuma/README
/usr/share/doc/yuma/yuma-quickstart-guide.pdf
/usr/share/doc/yuma/yuma-user-manual.pdf
%{_mandir}/man1/yangcli.1.gz
%{_mandir}/man1/yangdiff.1.gz
%{_mandir}/man1/yangdump.1.gz
%{_datadir}/yuma/modules/netconfcentral/yangcli.yang
%{_datadir}/yuma/modules/netconfcentral/yangdiff.yang
%{_datadir}/yuma/modules/netconfcentral/yangdump.yang

%changelog
*  Mon Feb 01 2010  Andy Bierman <andyb at iwl.com> 0.10.652
 - Supporting yang-10 draft
 - Add support for revision in module param (foo@2010-01-15)
 - Add feature CLI parms to control feature code generation
 - Fixed netconf-state bug; capabilities were not dynamic;
   changed capsval to a virtual node w/ callback
* Fri Jan 29 2010 Andy Bierman <andyb at iwl.com> 0.9.8.646
  - Align with yang-draft-10; add some bugfixes
* Sun Jan 17 2010 Andy Bierman <andyb at iwl.com> 0.9.8.636
  - First RPM build

%package server

Summary:  YANG-based Unified Modular Automation Tools (server-side)
Requires: openssh
Requires: libxml2
Requires: shlibs

%description server
Yuma Tools is a YANG-based NETCONF-over-SSH client and server
development toolkit.  The netconfd server includes an automated
central NETCONF protocol stack, based directly on YANG modules.

%files server
%defattr(-,root,root,-)
%{_sbindir}/netconfd
%{_sbindir}/netconf-subsystem
%{_sysconfdir}/yuma/netconfd-sample.conf
/usr/share/doc/yuma/yumatools-cs-license.pdf
/usr/share/doc/yuma/yumatools-legal-notices.pdf
/usr/share/doc/yuma/AUTHORS
/usr/share/doc/yuma/ChangeLog
/usr/share/doc/yuma/README
%{_libdir}/yuma/
%{_mandir}/man1/netconfd.1.gz
%{_mandir}/man1/netconf-subsystem.1.gz
%{_datadir}/yuma/modules/netconfcentral/netconfd.yang
%{_datadir}/yuma/modules/netconfcentral/toaster.yang
%{_datadir}/yuma/modules/netconfcentral/yuma-interfaces.yang
%{_datadir}/yuma/modules/netconfcentral/yuma-mysession.yang
%{_datadir}/yuma/modules/netconfcentral/yuma-nacm.yang
%{_datadir}/yuma/modules/netconfcentral/yuma-netconf.yang
%{_datadir}/yuma/modules/netconfcentral/yuma-proc.yang
%{_datadir}/yuma/modules/netconfcentral/yuma-system.yang
