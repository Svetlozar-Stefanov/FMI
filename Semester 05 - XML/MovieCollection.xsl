<?xml version="1.0"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    <xsl:output method="xml" version="1.0" indent="yes"/>
    <xsl:template match="/">
        <fo:root xmlns:fo="http://www.w3.org/1999/XSL/Format">
            <fo:layout-master-set>
                <fo:simple-page-master page-width="210mm" page-height="297mm"
                                       master-name="page-layout">
                    <fo:region-body/>
                    <fo:region-before background-color="#11235A" extent="100%"/>
                </fo:simple-page-master>
            </fo:layout-master-set>

            <fo:page-sequence master-reference="page-layout">
                <fo:flow flow-name="xsl-region-body">
                    <fo:block-container border="5pt solid #596FB7" padding="5pt" margin-top="50%">
                        <fo:block text-align="center" font-size="38pt"
                                  font-weight="bold" font-family="serif" color="#C6CF9B">
                            Movie Collection
                        </fo:block>
                        <fo:block text-align="center" font-size="38pt"
                                  font-weight="bold" font-family="serif" color="#C6CF9B">
                            Catalog
                        </fo:block>
                    </fo:block-container>
                    <fo:block text-align="center" margin-top="10%">
                        <fo:external-graphic src="resources/Clapperboard.png"
                                             content-width="scale-to-fit" width="25%" content-height="25%"/>
                    </fo:block>
                </fo:flow>
            </fo:page-sequence>

            <xsl:for-each select="MovieCollection/movies/movie">
                <xsl:sort select="title"/>
                <fo:page-sequence master-reference="page-layout">
                    <fo:flow flow-name="xsl-region-body">
                        <fo:block-container margin-top="5%">
                            <fo:block text-align="center" font-size="28pt"
                                      margin-bottom="2%"
                                      font-weight="bold" font-family="serif" color="#C6CF9B">
                                <xsl:value-of select="title"/> (<xsl:value-of select="year"/>)
                            </fo:block>
                            <fo:block text-align="center">
                                <fo:external-graphic src="{unparsed-entity-uri(poster/@image)}"
                                                     content-width="scale-to-fit" width="40%" content-height="40%"/>
                            </fo:block>
                        </fo:block-container>
                            <fo:block text-align="justify" font-size="16pt" font-family="serif" color="#F6ECA9"
                                      margin-left="15%" margin-right="15%" margin-top="5%">
                                <xsl:value-of select="description"/>
                            </fo:block>
                        <fo:block-container margin-top="5%">
                            <fo:block text-align="justify" font-size="18pt"
                                      font-family="serif" color="#F6ECA9"
                                      margin-left="15%" margin-right="15%" margin-top="5%">
                                Director:
                                <xsl:variable name="director_ref_id" select="./@director"/>
                                <xsl:for-each select="/MovieCollection/artists/artist">
                                    <xsl:if test="@id = $director_ref_id">
                                        <xsl:value-of select="./name"/>
                                    </xsl:if>
                                </xsl:for-each>
                            </fo:block>
                            <fo:block text-align="justify" font-size="18pt"
                                      font-family="serif" color="#F6ECA9"
                                      margin-left="15%" margin-right="15%" margin-top="2%">
                                Stars:
                                <xsl:call-template name="get_field_of_ref">
                                    <xsl:with-param name="element_list" select="./@stars"/>
                                    <xsl:with-param name="element_path" select="/MovieCollection/artists/artist"/>
                                    <xsl:with-param name="element_field" select="name"/>
                                </xsl:call-template>
                            </fo:block>
                            <fo:block text-align="justify" font-size="18pt"
                                      font-family="serif" color="#F6ECA9"
                                      margin-left="15%" margin-right="15%" margin-top="2%">
                                Genres:
                                <xsl:call-template name="get_field_of_ref">
                                    <xsl:with-param name="element_list" select="./@genres"/>
                                    <xsl:with-param name="element_path" select="/MovieCollection/genres/genre"/>
                                    <xsl:with-param name="element_field" select="''"/>
                                </xsl:call-template>
                            </fo:block>
                            IMDB Rating:
                            <xsl:value-of select="./budget"/>
                            <fo:block text-align="justify" font-size="18pt"
                                      font-family="serif" color="#F6ECA9"
                                      margin-left="15%" margin-right="15%" margin-top="2%">
                                Length:
                                <xsl:value-of select="./length"/>
                            </fo:block>
                            <fo:block text-align="justify" font-size="18pt"
                                      font-family="serif" color="#F6ECA9"
                                      margin-left="15%" margin-right="15%" margin-top="2%">
                                Budget:
                                <xsl:value-of select="./budget"/>
                            </fo:block>
                            <fo:block text-align="justify" font-size="18pt"
                                      font-family="serif" color="#F6ECA9"
                                      margin-left="15%" margin-right="15%" margin-top="2%">
                                Gross Worldwide:
                                <xsl:value-of select="./gross_worldwide"/>
                            </fo:block>
                            <fo:block text-align="justify" font-size="18pt"
                                      font-family="serif" color="#F6ECA9"
                                      margin-left="15%" margin-right="15%" margin-top="2%">
                                IMDb rating:
                                <xsl:value-of select="./rating"/>
                            </fo:block>

                        </fo:block-container>
                    </fo:flow>
                </fo:page-sequence>
            </xsl:for-each>
        </fo:root>
    </xsl:template>

    <xsl:template name="get_field_of_ref">
        <xsl:param name="element_list"/>
        <xsl:param name="element_path"/>
        <xsl:param name="element_field"/>
        <xsl:param name="separator" select="' '"/>

        <xsl:if test="normalize-space($element_list) != ''">
            <xsl:variable name="element_id" select="substring-before(concat($element_list, $separator), $separator)"/>
            <xsl:variable name="remaining_elements" select="substring-after($element_list, $separator)"/>

            <xsl:variable name="element_node" select="$element_path[@id = $element_id]"/>

            <xsl:if test="$element_node">
                <xsl:choose>
                    <xsl:when test="$element_field">
                        <xsl:for-each select="$element_node">
                            <xsl:value-of select="$element_field"/>
                        </xsl:for-each>
                    </xsl:when>
                    <xsl:otherwise>
                        <xsl:value-of select="$element_node"/>
                    </xsl:otherwise>
                </xsl:choose>
                <xsl:if test="normalize-space($remaining_elements) != ''">, </xsl:if>
            </xsl:if>

            <xsl:call-template name="get_field_of_ref">
                <xsl:with-param name="element_list" select="$remaining_elements"/>
                <xsl:with-param name="element_path" select="$element_path"/>
                <xsl:with-param name="element_field" select="$element_field"/>
                <xsl:with-param name="separator" select="$separator"/>
            </xsl:call-template>
        </xsl:if>
    </xsl:template>
</xsl:stylesheet>