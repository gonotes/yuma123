<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" 
	  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<?python import sitetemplate ?>

<html xmlns="http://www.w3.org/1999/xhtml" xmlns:py="http://purl.org/kid/ns#"
      py:extends="sitetemplate">

  <head py:match="item.tag=='{http://www.w3.org/1999/xhtml}head'" 
	py:attrs="item.items()">
    <meta content="text/html; charset=UTF-8" http-equiv="content-type" 
	  py:replace="''"/>
    <title py:replace="''">Your title goes here</title>
    <meta py:replace="item[:]" name="description" content="master template"/>
    <link rel="stylesheet" type="text/css" media="screen" 
	  href="../static/css/style.css"
          py:attrs="href=tg.url('/static/css/style.css')"/>

<script type="text/javascript"><!--//--><![CDATA[//><!--

sfHover = function() {
	var sfEls = document.getElementById("nav").getElementsByTagName("LI");
	for (var i=0; i<sfEls.length; i++) {
		sfEls[i].onmouseover=function() {
			this.className+=" sfhover";
		}
		sfEls[i].onmouseout=function() {
			this.className=this.className.replace(new RegExp(" sfhover\\b"), "");
		}
	}
}
if (window.attachEvent) window.attachEvent("onload", sfHover);

//--><!]]></script>


  <meta name="keywords"
	content="netconf, xml, yang, yangtools, configuration, 
         router configuration, configuration tools, yangdump, SMIv2"/>
  </head>
  <body py:match="item.tag=='{http://www.w3.org/1999/xhtml}body'" 
	py:attrs="item.items()">
    <table class="ncheader">
      <tr>
	<td>
	  <a href="${tg.url('/')}">
            <img src="${tg.url('/static/images/nc-logo.png')}" 
		 align="center" border="0" alt="netconfcentral logo" 
		 height="60" width="300"/>
	  </a>
	</td>
	<!--
	<td py:if="modmenu" class="ncheader_right">
	  ${modmenu.display()}
	</td>
	-->
	<td class="ncheader_right">
	  &nbsp;
	</td>
      </tr>
    </table>

    <div class="ncbanner">
      <ul id="nav">
	<li><a href="/">Home</a></li>
	<li><a href="">YANG&nbsp;Database</a>
	  <ul>
            <li class="daddy"><a href="">List&nbsp;All</a>
	      <ul>
		<li><a href="/modulelist">Modules</a></li>
		<li><a href="/typedeflist">Typedefs</a></li>
		<li><a href="/groupinglist">Groupings</a></li>
		<li><a href="/objectlist">Objects</a></li>
		<li><a href="/rpclist">RPC&nbsp;Methods</a></li>
		<li><a href="/notificationlist">Notifications</a></li>
		<li><a href="/extensionlist">Extensions</a></li>
	      </ul>
	    </li>
	    <li class="daddy"><a href="">Browse&nbsp;All</a>
	      <ul>
		<li><a href="/modulebrowse">Modules</a></li>
		<li><a href="/typedefbrowse">Typedefs</a></li>
		<li><a href="/groupingbrowse">Groupings</a></li>
		<li><a href="/objectbrowse">Objects</a></li>
		<li><a href="/rpcbrowse">RPC&nbsp;Methods</a></li>
		<li><a href="/notificationbrowse">Notifications</a></li>
		<li><a href="/extensionbrowse">Extensions</a></li>
	      </ul>
	    </li>
	    <li><a href="/search">Search</a></li>
	  </ul>
	</li>
	<li py:if="'member' in tg.identity.groups">
	  <a href="">Online&nbsp;Tools</a>
	  <ul>
	    <li><a href="/run_yangdump">Run&nbsp;yangdump</a></li>
	    <li><a href="/run_yangdiff">Run&nbsp;yangdiff</a></li>
          </ul>
	</li>
	<li py:if="'publisher' in tg.identity.groups">
	  <a href="">Publisher&nbsp;Tools</a>
	  <ul>
	    <li><a href="/run_yangdump">View&nbsp;modules</a></li>
	    <li><a href="/run_yangdump">Add&nbsp;module</a></li>
	    <li><a href="/run_yangdiff">Update&nbsp;module</a></li>
	    <li><a href="/run_yangdiff">Remove&nbsp;module</a></li>
	    <li><a href="/run_yangdiff">Remove&nbsp;update</a></li>
          </ul>
	</li>
	<li><a href="">Documentation</a>
	  <ul>
	    <li><a href="/database_docs">YANG&nbsp;database</a></li>
	    <li><a href="/yangdump_manual">yangdump&nbsp;program</a></li>
	    <li><a href="/yangdiff_manual">yangdiff&nbsp;program</a></li>
	    <li><a href="/netconf_docs">NETCONF&nbsp;protocol</a></li>
	    <li><a href="/yang_docs">YANG&nbsp;language</a></li>
	    <li><a href="/yang_auto">YANG-based&nbsp;automation</a></li>
	  </ul>
	</li>
	<li><a href="/download">Free&nbsp;Downloads</a></li>
	<li py:if="'admin' in tg.identity.groups">
	  <a href="/adminhome">Admin</a>
	  <ul>
	    <li><a href="/editmodules">Edit&nbsp;Modules</a></li>
	    <li><a href="/editusers">Edit&nbsp;Users</a></li>
	  </ul>
	</li>
	<li py:if="tg.config('identity.on') and 
		   not defined('logging_in') and tg.identity.anonymous">
          <a id="loginbar" href="${tg.url(tg.identity.login_url)}">Login</a>
	</li>
	<li py:if="tg.config('identity.on') and not 
		   defined('logging_in') and not tg.identity.anonymous">
          <a id="loginbar" href="${tg.url('/logout')}">Logout</a>
	</li>
	<li id="loggedin"
	    py:if="tg.config('identity.on') and not 
		   defined('logging_in') and not tg.identity.anonymous">
          ${tg.identity.user.display_name or 
	  tg.identity.user.user_name}&nbsp;is&nbsp;logged&nbsp;in
	</li>
      </ul>
    </div>

    <div id="main_content">
      <div id="status_block" class="flash"
           py:if="value_of('tg_flash', None)" py:content="tg_flash"></div>
      <div py:replace="[item.text]+item[:]">page content</div>
    </div>

    <div id="footer">
      <hr />
      <p>
	YangTools 0.9.4, Copyright &#169; 2008, 2009, Andy Bierman
      </p>
      <p py:if="copyright">
	TurboGears is Copyright &#169; 2007, Kevin Dangoor
      </p>
    </div>
  </body>

</html>