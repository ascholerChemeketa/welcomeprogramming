<?xml version='1.0'?> <!-- As XML file -->

<!--
Used for custom overrides and temporary patches
-->

<!-- http://pimpmyxslt.com/articles/entity-tricks-part2/ -->
<!DOCTYPE xsl:stylesheet [
    <!ENTITY % entities SYSTEM "./core/entities.ent">
    %entities;
]>

<!-- Identify as a stylesheet -->
<xsl:stylesheet
    xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
    xmlns:xml="http://www.w3.org/XML/1998/namespace"
    xmlns:svg="http://www.w3.org/2000/svg"
    xmlns:xlink="http://www.w3.org/1999/xlink"
    xmlns:pi="http://pretextbook.org/2020/pretext/internal"
    xmlns:exsl="http://exslt.org/common"
    xmlns:date="http://exslt.org/dates-and-times"
    xmlns:str="http://exslt.org/strings"
    xmlns:fn="http://www.w3.org/2005/xpath-functions"
    xmlns:pf="https://prefigure.org"
    exclude-result-prefixes="svg xlink pi fn pf"
    extension-element-prefixes="exsl date str"
>

  <!-- <xsl:import href="../../../pretext/xsl/pretext-html.xsl"/> -->
  <xsl:import href="./core/pretext-html.xsl"/>

</xsl:stylesheet>