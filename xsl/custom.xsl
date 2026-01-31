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

<xsl:template match="interactive[@platform = 'javascript']/script[@type]">
    <script>
        <xsl:if test="@type">
          <xsl:attribute name="type">
            <xsl:value-of select="@type"/>
          </xsl:attribute>
        </xsl:if>
        <xsl:value-of select="."/>
    </script>
</xsl:template>

  <!-- wide interactives -->
  <xsl:template match="interactive[@iframe]" mode="iframe-interactive">
      <!-- Distinguish netowk location versus (external) file -->
      <xsl:variable name="b-network-location" select="(substring(@iframe, 1, 7) = 'http://') or
                                                      (substring(@iframe, 1, 8) = 'https://')"/>

      <xsl:variable name="location">
          <!-- prefix with directory information if not obviously a network location -->
          <xsl:if test="not($b-network-location)">
              <!-- empty when not using managed directories -->
              <xsl:value-of select="$external-directory"/>
          </xsl:if>
          <xsl:value-of select="@iframe"/>
      </xsl:variable>
      <xsl:variable name="width-percent">
          <xsl:apply-templates select="." mode="get-width-percentage" />
      </xsl:variable>
      <xsl:variable name="width-value" select="substring($width-percent, 1, string-length($width-percent) - 1)"/>
      <iframe src="{$location}">
          <xsl:apply-templates select="." mode="html-id-attribute"/>
          <xsl:apply-templates select="." mode="size-pixels-attributes"/>
          <xsl:apply-templates select="." mode="iframe-dark-mode-attribute" />
          <xsl:if test="number($width-value) &gt; 100">
              <xsl:attribute name="class">wide-iframe</xsl:attribute>
          </xsl:if>
      </iframe>
  </xsl:template>
</xsl:stylesheet>