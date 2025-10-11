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

<xsl:import href="./core/pretext-html.xsl"/>



<!-- Make use of PR before release -->
<xsl:template match="exercise|&PROJECT-LIKE;|task" mode="runestone-manifest">
    <xsl:variable name="manifestable-interactives-fenced">|truefalse|multiplechoice|parson|parson-horizontal|cardsort|matching|clickablearea|select|fillin-basic|fillin|coding|shortanswer|webwork-reps|</xsl:variable>
    <xsl:if test="contains($manifestable-interactives-fenced, concat('|', @exercise-interactive, '|'))">
        <question>
            <!-- A divisional exercise ("exercises/../exercise") is not really   -->
            <!-- a reading activity in the Runestone model, so we flag these     -->
            <!-- exercises as such.  Also, interactive "task" come through here, -->
            <!-- so we need to look to an ancestor to see if the containing      -->
            <!-- "exercise" is divisional. The @optional attribute matches the   -->
            <!-- "optional" flag in the Runestone database.  We simply set the   -->
            <!-- value to "yes" and never bother to say "no".  The  only         -->
            <!-- consumer is the import into the Runestone database, so any      -->
            <!-- change needs only coordinate there.                             -->
            <xsl:if test="(@exercise-customization = 'divisional') or
                          (self::task and ancestor::exercise[@exercise-customization = 'divisional'])">
                <xsl:attribute name="optional">
                    <xsl:text>yes</xsl:text>
                </xsl:attribute>
            </xsl:if>
            <!-- label is from the "exercise" -->
            <xsl:apply-templates select="." mode="runestone-manifest-label"/>
            <!-- Duplicate, but still should look like original (ID, etc.),  -->
            <!-- not knowled. Solutions are available in the originals, via  -->
            <!-- an "in context" link off the Assignment page                -->
            <htmlsrc>
                <!-- next template produces nothing, unless the  -->
                <!-- "exercise" is in an "exercisegroup" ("eg")  -->
                <xsl:apply-templates select="." mode="eg-introduction"/>
                <xsl:choose>
                    <!-- with "webwork" guts, the HTML is exceptional -->
                    <xsl:when test="@exercise-interactive = 'webwork-reps'">
                        <xsl:apply-templates select="." mode="webwork-core">
                            <xsl:with-param name="b-original" select="true()"/>
                        </xsl:apply-templates>
                    </xsl:when>
                    <xsl:otherwise>
                        <!-- next template collects "introduction" preceding a "task" -->
                        <!-- Note: we are explicitly dodging webwork/task             -->
                        <xsl:apply-templates select="." mode="task-introductions"/>

                        <xsl:apply-templates select="."  mode="exercise-components">
                            <xsl:with-param name="b-original" select="true()"/>
                            <xsl:with-param name="block-type" select="'visible'"/>
                            <xsl:with-param name="b-has-statement" select="true()" />
                            <xsl:with-param name="b-has-hint"      select="true()" />
                            <xsl:with-param name="b-has-answer"    select="false()" />
                            <xsl:with-param name="b-has-solution"  select="false()" />
                        </xsl:apply-templates>

                        <!-- next template collects "conclusion" preceding a "task" -->
                        <!-- Note: we are explicitly dodging webwork/task           -->
                        <xsl:apply-templates select="." mode="task-conclusions"/>
                    </xsl:otherwise>
                </xsl:choose>
            </htmlsrc>
        </question>
    </xsl:if>
    <!-- The match for this template will include "exercise" and &PROJECT-LIKE  -->
    <!-- that are just containers for a bunch of "task".  In other words, they  -->
    <!-- will not be marked with the "@exercise-interactive" attribute.  So the -->
    <!-- "xsl:if" above will fail.  And right here is a dead-end.  We need to   -->
    <!-- recurse into "task" for the possibility they are marked with           -->
    <!-- "@exercise-interactive" so they can potentially get placed properly in -->
    <!-- the manifest.                                                          -->
    <xsl:apply-templates select="task" mode="runestone-manifest"/>
</xsl:template>

</xsl:stylesheet>
