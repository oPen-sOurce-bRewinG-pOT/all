// FRAME BUSTER
  /*if (window.top != window) {
      window.top.location.replace (window.location.href);
  }*/
  
// get windowheight and width  
var winWidth = 0, winHeight = 0;
if( typeof( window.innerWidth ) == 'number' ) {
	//Non-IE
	winWidth = window.innerWidth;
	winHeight = window.innerHeight;
} else if( document.documentElement && ( document.documentElement.clientWidth || document.documentElement.clientHeight ) ) {
	//IE 6+ in 'standards compliant mode'
	winWidth = document.documentElement.clientWidth;
	winHeight = document.documentElement.clientHeight;
} else if( document.body && ( document.body.clientWidth || document.body.clientHeight ) ) {
	//IE 4 compatible
	winWidth = document.body.clientWidth;
	winHeight = document.body.clientHeight;
}


function updateWin(url) {
	updateWindow = window.open(url,'update','toolbar=0,location=0,directories=0,status=0,menubar=0,scrollbars=0,resizable=1,width=455,height=570');
 }
/* OPENS A POPUP WINDOW OF A SPECIFIED SIZE */
function openindex(width,height,theurl,scrollbars) { 
	OpenWindow=window.open(theurl, "newwin", "height="+height+", width=" + width + ",toolbar=no,scrollbars=" + scrollbars + ",menubar=no,resizable=yes");
self.name="main";
}

function popforgotpassword () {
	openindex(430,200,'/pops/forgotpassword.cfm',0);
}
function rememberme () {
	openindex(430,255,'/pops/rememberme.cfm',0);
}
function poparchive(qid,turn) {
	openindex(480,360,'/pops/archive.cfm?qid=' + qid + '&turn=' + turn,1);
}
function poparchivefaqs(fid,turn) {
	openindex(480,360,'/pops/archivefaqs.cfm?fid=' + fid + '&turn=' + turn,1);
}

function tipvote(postid) {
	openindex(450,250,'/pops/tipvote.cfm?id='+ postid + '&votes=1&w=450&h=250');
}
function redflag(postid) {
	openindex(600,450,'/pops/redflag.cfm?id='+ postid + '&votes=1&w=600&h=450');
}

function cont(email) {
	var qry = "";
	var win = "/pops/contact.cfm";
	var left = (screen.width/2) - 300;
	var top = (screen.height/2) - 215;
	if (email.length > 0) qry = "?email=" + email; 
	OpenWindow = null;
	OpenWindow = window.open(win + qry, "newwin", 'height=430, width=600,toolbar=no,scrollbars=' + 1 + ',menubar=no,resizable=yes,status=no,left='+left+',top='+top+',screenX='+left+',screenY='+top);
	OpenWindow.focus();
	self.name = "main";
}

function conterr() {
	var win = "/pops/contacterr.cfm";
	var left = (screen.width/2) - 300;
	var top = (screen.height/2) - 215;
	OpenWindow = null;
	OpenWindow = window.open(win, "newwin", 'height=430, width=600,toolbar=no,scrollbars=' + 1 + ',menubar=no,resizable=yes,status=no,left='+left+',top='+top+',screenX='+left+',screenY='+top);
	OpenWindow.focus();
	self.name = "main";
}

// Drop-in content box- By Dynamic Drive
// For full source code and more DHTML scripts, visit http://www.dynamicdrive.com
// This credit MUST stay intact for use

var ie=document.all
var dom=document.getElementById
var ns4=document.layers
var calunits=document.layers? "" : "px"

var bouncelimit=32 //(must be divisible by 8)
var direction="up"

function initbox(){
if (!dom&&!ie&&!ns4)
return
crossobj=(dom)?document.getElementById("dropin").style : ie? document.all.dropin : document.dropin
scroll_top=(ie)? truebody().scrollTop : window.pageYOffset
crossobj.top=scroll_top-250+calunits
crossobj.visibility=(dom||ie)? "visible" : "show"
dropstart=setInterval("dropin()",50)
}

function dropin(){
scroll_top=(ie)? truebody().scrollTop : window.pageYOffset
if (parseInt(crossobj.top)<80+scroll_top)
crossobj.top=parseInt(crossobj.top)+40+calunits
else{
clearInterval(dropstart)
bouncestart=setInterval("bouncein()",50)
}
}

function bouncein(){
crossobj.top=parseInt(crossobj.top)-bouncelimit+calunits
if (bouncelimit<0)
bouncelimit+=8
bouncelimit=bouncelimit*-1
if (bouncelimit==0){
clearInterval(bouncestart)
}
}

function dismissbox(){
if (window.bouncestart) clearInterval(bouncestart)
crossobj.visibility="hidden"
}

function truebody(){
return (document.compatMode && document.compatMode!="BackCompat")? document.documentElement : document.body
}



function doPopup() {
	initbox();
}


function getStyleClass (className) {
	for (var s = 0; s < document.styleSheets.length; s++)
	{
		if(document.styleSheets[s].rules)
		{
			for (var r = 0; r < document.styleSheets[s].rules.length; r++)
			{
				if (document.styleSheets[s].rules[r].selectorText == '.' + className)
				{
					return document.styleSheets[s].rules[r];
				}
			}
		}
		else if(document.styleSheets[s].cssRules)
		{
			for (var r = 0; r < document.styleSheets[s].cssRules.length; r++)
			{
				if (document.styleSheets[s].cssRules[r].selectorText == '.' + className)
					return document.styleSheets[s].cssRules[r];
			}
		}
	}
	
	return null;
}
function gofaq(pid,fid) {
	var theURL = "faqs.cfm?pid="+pid+"&fid="+fid; 
	window.top.location.href=theURL;
}
function gothread(pid,qid) {
	var theURL = "viewthread.cfm?qid="+qid;
	window.top.location.href=theURL;
}
function goforum(pid) {
	var theURL = "threadminder.cfm?pid="+pid;
	window.top.location.href=theURL;
}
function golink(pid) {
	var theURL = "links.cfm?pid="+pid;
	window.top.location.href=theURL;
}

$.fn.br2nl = function(){
    return this.each(function(){
        var that = $(this);
        that.html(that.html().replace(/<br\s*[\/]?>\r\n/gi, "\r\n").replace(/<br\s*[\/]?>\n/gi, "\r\n").replace(/<br\s*[\/]?>/gi, "\r\n",'b'));
    });
};



    /*
 Rangy Text Inputs, a cross-browser textarea and text input library plug-in for jQuery.

 Part of Rangy, a cross-browser JavaScript range and selection library
 http://code.google.com/p/rangy/

 Depends on jQuery 1.0 or later.

 Copyright 2010, Tim Down
 Licensed under the MIT license.
 Version: 0.1.205
 Build date: 5 November 2010
*/
(function(n){function o(e,g){var a=typeof e[g];return a==="function"||!!(a=="object"&&e[g])||a=="unknown"}function p(e,g,a){if(g<0)g+=e.value.length;if(typeof a=="undefined")a=g;if(a<0)a+=e.value.length;return{start:g,end:a}}function k(){return typeof document.body=="object"&&document.body?document.body:document.getElementsByTagName("body")[0]}var i,h,q,l,r,s,t,u,m;n(document).ready(function(){function e(a,b){return function(){var c=this.jquery?this[0]:this,d=c.nodeName.toLowerCase();if(c.nodeType==
1&&(d=="textarea"||d=="input"&&c.type=="text")){c=[c].concat(Array.prototype.slice.call(arguments));c=a.apply(this,c);if(!b)return c}if(b)return this}}var g=document.createElement("textarea");k().appendChild(g);if(typeof g.selectionStart!="undefined"&&typeof g.selectionEnd!="undefined"){i=function(a){return{start:a.selectionStart,end:a.selectionEnd,length:a.selectionEnd-a.selectionStart,text:a.value.slice(a.selectionStart,a.selectionEnd)}};h=function(a,b,c){b=p(a,b,c);a.selectionStart=b.start;a.selectionEnd=
b.end};m=function(a,b){if(b)a.selectionEnd=a.selectionStart;else a.selectionStart=a.selectionEnd}}else if(o(g,"createTextRange")&&typeof document.selection=="object"&&document.selection&&o(document.selection,"createRange")){i=function(a){var b=0,c=0,d,f,j;if((j=document.selection.createRange())&&j.parentElement()==a){f=a.value.length;d=a.value.replace(/\r\n/g,"\n");c=a.createTextRange();c.moveToBookmark(j.getBookmark());j=a.createTextRange();j.collapse(false);if(c.compareEndPoints("StartToEnd",j)>
-1)b=c=f;else{b=-c.moveStart("character",-f);b+=d.slice(0,b).split("\n").length-1;if(c.compareEndPoints("EndToEnd",j)>-1)c=f;else{c=-c.moveEnd("character",-f);c+=d.slice(0,c).split("\n").length-1}}}return{start:b,end:c,length:c-b,text:a.value.slice(b,c)}};h=function(a,b,c){b=p(a,b,c);c=a.createTextRange();var d=b.start-(a.value.slice(0,b.start).split("\r\n").length-1);c.collapse(true);if(b.start==b.end)c.move("character",d);else{c.moveEnd("character",b.end-(a.value.slice(0,b.end).split("\r\n").length-
1));c.moveStart("character",d)}c.select()};m=function(a,b){var c=document.selection.createRange();c.collapse(b);c.select()}}else{k().removeChild(g);window.console&&window.console.log&&window.console.log("TextInputs module for Rangy not supported in your browser. Reason: No means of finding text input caret position");return}k().removeChild(g);l=function(a,b,c,d){var f;if(b!=c){f=a.value;a.value=f.slice(0,b)+f.slice(c)}d&&h(a,b,b)};q=function(a){var b=i(a);l(a,b.start,b.end,true)};u=function(a){var b=
i(a),c;if(b.start!=b.end){c=a.value;a.value=c.slice(0,b.start)+c.slice(b.end)}h(a,b.start,b.start);return b.text};r=function(a,b,c,d){var f=a.value;a.value=f.slice(0,c)+b+f.slice(c);if(d){b=c+b.length;h(a,b,b)}};s=function(a,b){var c=i(a),d=a.value;a.value=d.slice(0,c.start)+b+d.slice(c.end);c=c.start+b.length;h(a,c,c)};t=function(a,b,c){var d=i(a),f=a.value;a.value=f.slice(0,d.start)+b+d.text+c+f.slice(d.end);b=d.start+b.length;h(a,b,b+d.length)};n.fn.extend({getSelection:e(i,false),setSelection:e(h,
true),collapseSelection:e(m,true),deleteSelectedText:e(q,true),deleteText:e(l,true),extractSelectedText:e(u,false),insertText:e(r,true),replaceSelectedText:e(s,true),surroundSelectedText:e(t,true)})})})(jQuery);



/*$.fn.windowcenter = function () {
    this.css("position","absolute");
    this.css("top", ( $(window).height() - this.height() ) / 2+$(window).scrollTop() + "px");
    this.css("left", ( $(window).width() - this.width() ) / 2+$(window).scrollLeft() + "px");
    return this;
}*/
// initialise page
$(function(){
	$('ul.sf-menu').superfish({
		animation: {opacity:'show',height:'show'},
		speed: 'fast',
		autoArrows: false,
		disableHI	: true,
		delay: 400
	}).find('ul').bgIframe({opacity:false});


	$(".tgml #code div.body, .tgml .code div.body, div.tgml code div.body").br2nl();
	$(".tgml #code div.body, .tgml .code div.body, .tgml code div.body").replaceWith(function() {
			return '<pre class="body">' + $(this).html() + '</pre>'});
	
	// MAKE SURE FLASH MOVIES HAVE WMODE="TRANSPARENT"
	$("object").append(
		$("<param/>").attr({
			'name': 'wmode',
			'value': 'transparent'
		})
	).find("embed").attr('wmode', 'transparent');		



//MORE LIKE THIS LINKS

	$('.threadlink').after(function() {
		return '&nbsp;<a class="mltlink" href="#" data-qid="' + $(this).closest('[data-qid]').data("qid") + '"><img src="/img/icons/sm/dna.png" alt="" title="More Threads Like This"></a>'});
	$('body').append('<div id="mlt" />');
	$('#morethreadslikethis, .morethreadslikethis, .mltlink').click(function (e) {
		var a=this;
		e.preventDefault();
		$(function ()    {
			$('#mlt').dialog({
				modal: true,
				position: {my:"center", at: "center", of: window },
				autoOpen:true,
				open: function ()
				{ 
					$(this).html('');
					$(this).load("/tools/morelikethis.cfm?qid=" + $(a).data("qid"));
				},
				height: 400,
				width: 550,
				title: 'More Threads Like This',
				show:"slow"
			});
			return false;
		});
	});


});

