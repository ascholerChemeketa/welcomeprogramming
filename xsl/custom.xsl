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



<xsl:template match="interactive" mode="interactive-sizing-style-attribute">
    <xsl:param name="default-aspect" select="'1:1'" />
    <xsl:variable name="resize-behavior">
        <xsl:apply-templates select="." mode="get-resize-behavior"/>
    </xsl:variable>
    <!-- tag wide interactives with some data attributes that styling/js can use -->
    <xsl:if test="@design-width != ''">
        <xsl:attribute name="data-design-width">
            <xsl:value-of select="@design-width"/>
        </xsl:attribute>
        <!-- css can't easily test numerics, so provide hint this content is wide -->
        <xsl:if test="@design-width > $html-design-width">
            <xsl:attribute name="data-design-width-wide"/>
        </xsl:if>
    </xsl:if>
    <xsl:choose>
        <xsl:when test="$resize-behavior = 'responsive'">
            <xsl:attribute name="style">
                <xsl:variable name="max-width">
                    <xsl:choose>
                        <xsl:when test="@design-width != ''">
                            <xsl:value-of select="@design-width"/>
                            <xsl:text>px</xsl:text>
                        </xsl:when>
                        <xsl:otherwise>
                            <xsl:apply-templates select="." mode="get-width-percentage"/>
                        </xsl:otherwise>
                    </xsl:choose>
                </xsl:variable>
                <xsl:variable name="aspect-ratio">
                    <xsl:apply-templates select="." mode="get-aspect-ratio">
                        <xsl:with-param name="default-aspect" select="'1:1'" />
                    </xsl:apply-templates>
                </xsl:variable>
                <xsl:text>max-width: </xsl:text>
                <xsl:value-of select="$max-width"/>
                <xsl:text>; </xsl:text>
                <xsl:text>width: 100%; </xsl:text>
                <xsl:text>aspect-ratio:</xsl:text>
                <xsl:value-of select="$aspect-ratio"/>
            </xsl:attribute>
        </xsl:when>
        <xsl:otherwise>
            <!-- resize-behavior: fixed-height -->
            <xsl:apply-templates select="." mode="size-pixels-style-attribute"/>
        </xsl:otherwise>
    </xsl:choose>
</xsl:template>

</xsl:stylesheet>